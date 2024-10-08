#include <fstream>
#include <iostream>

class DataReader{

protected:

	std::ifstream m_in;
	std::string m_filename;
	uint8_t* m_data;
	uint8_t m_n;

public:

	DataReader(const std::string& filename) : m_filename(filename), m_n(0), m_data(nullptr) {}

	virtual ~DataReader() {}

	virtual bool Open() = 0;

	void Close(){

		m_in.close();

	}

	virtual void Read() = 0;

	virtual void Write() = 0;

	void GetData(uint8_t* buf, uint8_t& n){

		n = m_n;

		for (int i = 0; i < m_n; i++) {

			buf[i] = m_data[i];
		}

	}

};

class BinfReader : public DataReader {

	BinfReader(const std::string& filename) : DataReader(filename) {}

	bool Open() override{

		m_in.open(m_filename, std::ios::binary);

		if (!m_in.is_open()) {

			return false;

		}

		return true;

	}

	void Read() override{

		m_in.read(reinterpret_cast<char*>(&m_n), sizeof(unsigned int));
		m_data = new uint8_t[m_n * sizeof(float)];
		m_in.read(reinterpret_cast<char*>(m_data), m_n * sizeof(float));

	}

	void Write() override {}

};

class TxtReader : public DataReader{

public:

	TxtReader(const std::string& filename) : DataReader(filename) {}

	virtual ~TxtReader(){

		if (m_data != nullptr) {

			delete[] m_data;

		}

	}

	bool Open() override{

		m_in.open(m_filename);

		if (!m_in.is_open()) {

			return false;

		}

		return true;

	}

	void Read() override{

		int tmp;

		m_in >> tmp;
		m_n = tmp;
		m_data = new uint8_t[m_n];

		for (int i = 0; i < m_n; i++){

			int tmp;

			m_in >> tmp;
			m_data[i] = tmp;

		}

	}

	void Write() override{}

};

class BinReader : public DataReader{

public:

	BinReader(const std::string& filename) : DataReader(filename) {}

	virtual ~BinReader(){

		if (m_data != nullptr) {

			delete[] m_data;

		}

	}

	bool Open() override{

		m_in.open(m_filename, std::ios::binary);

		if (!m_in.is_open()) {

			return false;

		}

		return true;

	}

	void Read() override{

		m_in.read((char*)&m_n, 1);
		m_data = new uint8_t[m_n];
		m_in.read((char*)m_data, m_n);

	}

	void Write() override{}

};

DataReader* Factory(const std::string& filename){

	std::string extension = filename.substr(filename.find_last_of('.') + 1);

	if (extension == "txt") {

		return new TxtReader(filename);

	}

	else if (extension == "bin") {

		return new BinReader(filename);

	}

	else if (extension == "binf") {

		return new BinfReader(filename);

	};

	return nullptr;

}

int main(){

	uint8_t n;
	uint8_t buf[100];

	DataReader* Reader = Factory("input2.bin");

	if (Reader == nullptr) {

		return -1;

	}

	Reader->Open();
	Reader->Read();
	Reader->GetData(buf, n);

	std::cout << (int)n << std::endl;

	for (int i = 0; i < n; i++) {

		std::cout << (int)buf[i] << std::endl;

	}

	delete Reader;

}
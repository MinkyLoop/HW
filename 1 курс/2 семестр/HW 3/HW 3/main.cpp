#include <iostream>
#include <algorithm>

class String {

	char* m_data;
	size_t m_length;

  public:

	String() : m_length(0), m_data(new char[1]) {
	
		m_data[0] = '\0'; // Нуль-терминатор(конец строки)
		
		std::cout << "Constr" << ::std::endl;
	
	} // Дефолтный конструктор

	String(const char* arr){

		int len = 0;

		for (int i = 0; arr[i] != '\0'; i++) {

			len++;

		}

		char* tmp = new char[len+1];

		for (int i = 0; i < len; i++) {

			tmp[i] = arr[i];

		}

		m_data = tmp;
		m_length = len;
		m_data[len] = '\0';

	}

	String(const String& other) : m_length(other.m_length) {// Конструктор копирования

		m_data = new char[m_length + 1];

		for (int i = 0; i < m_length; i++) {
		
			m_data[i] = other.m_data[i];

		}

		m_data[m_length] = '\0';

		std::cout << "Copy Constr" << std::endl;

	}

	String& operator=(const String& other) {// Оператора присваивания

		if (this != &other) {

			delete[] m_data;

			m_length = other.m_length;
			m_data = new char[m_length + 1];

			for (int i = 0; i < m_length; i++) {

				m_data[i] = other.m_data[i];

			}

			m_data[m_length] = '\0';

		}

		std::cout << "Copy Assign Oper" << std::endl;

		return *this;	

	}

	~String() {// Деструктор

		delete[] m_data;
		
		std::cout << "Destr " << m_length << std::endl;
		
	}

	String operator+(const String& other) {

		String tmp;

		tmp.m_length = m_length + other.m_length;
		tmp.m_data = new char[tmp.m_length + 1];

		

		for (int i = 0; i < m_length; i++) {

			tmp.m_data[i] = m_data[i];
			//std::cout << i << " " << m_data[i] << std::endl;

		}
		int i = m_length;

		for (int j = 0; j < other.m_length; j++, i++) {

			tmp.m_data[i] = other.m_data[j];
			//std::cout << i << " " << other.m_data[j] << std::endl;

		}
		
		tmp.m_data[tmp.m_length] = '\0';
		//std::cout << tmp.m_data << std::endl;
		return tmp;

	}

	String& operator+=(const String& other) {

		int len = m_length;

		m_length += other.m_length;
		char* n_data = new char[m_length + 1];

		for (int i = 0; i < len; i++) {

			n_data[i] = m_data[i];

		}

		for (int j = 0; j < m_length; j++, len++) {

			n_data[len] = other.m_data[j];

		}

		n_data[m_length] = '\0';

		delete[] m_data;
		m_data = n_data;

		return *this;

	}

	char& operator[](int index) {

		return m_data[index];

	}

	bool operator<(const String& other) {

		int len = std::min(m_length, other.m_length);

		for (int i = 0; i < len; i++) {

			if (m_data[i] != other.m_data[i]) {

				return m_data[i] < other.m_data[i];

			}

		}

	}

	bool operator>(const String& other) {

		int len = std::min(m_length, other.m_length);

		for (int i = 0; i < len; i++) {

			if (m_data[i] != other.m_data[i]) {

				return m_data[i] > other.m_data[i];

			}

		}

	}

	bool operator==(const String& other) {

		if (m_length != other.m_length) {

			return false;

		}

		for (int i = 0; i < m_length; i++) {

			if (m_data[i] != other.m_data[i]) {

				return false;

			}

		}

		return true;

	}

	int length() {

		return m_length;

	}

	char* c_str() {

		return m_data;

	}

	int find(char sym) {

		for (int i = 0; i < m_length; i++) {

			if (m_data[i] == sym) {

				return i;

			}

		}

		return -1; // Если нету

	}

	char& at(int index) {

		if (index < 0 || index >= m_length) {

			std::cout << "Out of range\0";

		}
		else { 
			
			return m_data[index];
		
		}

	}

	friend std::ostream& operator<<(std::ostream& os, String& str) {
		os << str.m_data;
		return os;
	
	};

	friend std::istream& operator>>(std::istream& is, String& str) {
		char letter;
		char* tmp = new char[10000];
		int len = 0;
		is >> tmp;

		delete[] str.m_data;

	
		for (int i = 0; tmp[i] != '\0'; i++) {

			len++;

		}

		str.m_data = new char[len+1];
		std::copy(tmp, tmp + len + 1, str.m_data);
		str.m_length = len;
		delete[] tmp;
		return is;

	}

};

void main() {

	String s1;

	

	String s2 = "Apple";
	
	std::cout << s2.length() << std::endl;

	String s3 = "Banana";

	std::cout << s3.c_str() << std::endl;
	
	String s4 = s2 + s3;
	
	s1 = s4;

	s2 += s3;

	std::cout << s2 << std::endl;

	std::cin >> s1;

	std::cout << s1[0] << std::endl;

	s1[0] = 'h';

	std::cout << (s1 < s2) << std::endl;

	std::cout << s1.find('a') << std::endl;
	s3.at(100);
	//std::cout << s3.at(100) << std::endl;
}
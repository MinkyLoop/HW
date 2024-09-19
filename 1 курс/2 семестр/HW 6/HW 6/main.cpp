#include <iostream>
#include <cstdint>
#include <vector>

class BoolVectorProxy {

	uint8_t& byte;
	const size_t bitIndex;

  public:

	BoolVectorProxy(uint8_t& byte, size_t bitIndex) : byte(byte), bitIndex(bitIndex) {}

	BoolVectorProxy& operator=(bool value) {

		if (value) {

			byte |= (1 << bitIndex);

		}
		else {

			byte &= ~(1 << bitIndex);

		}

		return *this;
	}

	operator bool() const {

		return (byte >> bitIndex) & 1;

	}

};

template <size_t N>
class BitVect {

	std::vector<uint8_t> data;
	size_t length = N;

  public:
    
	BitVect() : data((N + 7) / 8, 0) {}

	void push_back(bool value) {
		
		size_t old_length = length;

		length += 1;
		
		if ((old_length + 7) / 8 != (length + 7) / 8) {

			std::vector<uint8_t> newData((length + 7) / 8, 0);

			for (size_t i = 0; i < old_length; i++) {

				size_t index = i / 8;
				size_t bit = i % 8;

				newData[index] |= ((data[index] >> bit) & 1) << bit;

			}

			data.swap(newData);

		}

		size_t index = (length - 1) % 8;
		
		data.back() |= value << index;

	}

	BoolVectorProxy operator[](size_t index) {

		return BoolVectorProxy(data[index / 8], index % 8);

	}

	size_t size() {

		return length;

	}

	void insert(size_t ind, bool value) {

		size_t old_length = length;

		length += 1;
		
		std::vector<uint8_t> newData((length + 7) / 8, 0);

		for (size_t i = 0; i < ind; i++) {

			size_t index = i / 8;
			size_t bit = i % 8;

			newData[index] |= ((data[index] >> bit) & 1) << bit;

		}

		newData[ind / 8] |= (value << (ind % 8));

		for (size_t i = ind + 1; i < length; i++) {

			size_t index = (i - 1) / 8;
			size_t bit = (i - 1) % 8;

			newData[i / 8] |= ((data[index] >> bit) & 1) << bit;

		}

		data.swap(newData);

	}

	void erase(size_t ind) {
		
		size_t old_length = length;

		length -= 1;

		std::vector<uint8_t> newData(length, 0);

		for (size_t i = 0; i < ind; i++) {

			newData[i] = (*this)[i];

		}

		for (size_t i = ind; i < length; i++) {

			newData[i] = (*this)[i + 1];

		}

		data.swap(newData);

	}

};

void main() {

	BitVect<8> bv;

	std::cout << bv.size() << std::endl;

	bv.insert(3, true);

	std::cout << bv.size() << std::endl;
	
	for (size_t i = 0; i < bv.size(); ++i) {
		std::cout << bv[i] << " ";
	}

	std::cout << std::endl;

	bv.erase(3);

	std::cout << bv.size() << std::endl;

	for (size_t i = 0; i < bv.size(); ++i) {
		std::cout << bv[i] << " ";
	}

	std::cout << std::endl;

	std::cout << bv[3];

}
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Bigint {

	std::vector<int> number;

  public:

	Bigint() {}

	Bigint(const std::string& num) {

		for (char c : num) {

			number.push_back(c - '0');

		}

	}

	Bigint(Bigint& other) : number(other.number) {}

	~Bigint() {}

	Bigint& operator=(const Bigint& other) {

		if (this != &other) {

			number = other.number;

		}
		return *this;

	}

	Bigint operator+(const Bigint& other) const{

		Bigint result;

		int sum = 0;
		int i = number.size() - 1, j = number.size() - 1;

		while (i >= 0 || j >= 0 || sum > 0) {

			if (i >= 0) {

				sum += number[i--];

			}

			if (j >= 0) {

				sum += other.number[j--];

			}

			result.number.insert(result.number.begin(), sum % 10);

			sum /= 10;

		}

		return result;

	}

	Bigint& operator+=(const Bigint& other) {

		*this = *this + other;

		return *this;

	}	

	Bigint operator*(const Bigint& other) const {

		Bigint result;

		int num1 = 0, num2 = 0;
		int power1 = number.size() - 1, power2 = other.number.size() - 1;

		for (int digit : number) {
			num1 += digit * pow(10, power1);
			power1--;
		}

		for (int digit : other.number) {
			num2 += digit * pow(10, power2);
			power2--;
		}

		int mult = num1 * num2;

		while (mult > 0) {

			result.number.insert(result.number.begin(), mult % 10);

			mult /= 10;

		}

		return result;

	}

	Bigint& operator*=(const Bigint& other) {

		*this = *this * other;

		return *this;

	}

	bool operator<(const Bigint& other) const {

		if (number.size() != other.number.size()) {

			return number.size() < other.number.size();

		}

		for (int i = 0; i < number.size(); i++) {

			if (number[i] != other.number[i]) {
			
				return number[i] < other.number[i];
			
			}

		}

		return false;

	}

	bool operator>(const Bigint& other) const {

		return other < *this;

	}

	bool operator==(const Bigint& other) const {

		return number == other.number;

	}

	bool operator != (const Bigint& other) const {

		return !(*this == other);

	}

	friend std::ostream& operator<<(std::ostream& os, const Bigint& num) {

		for (int digit : num.number) {

			os << digit;

		}

		return os;

	}

	friend std::istream& operator>>(std::istream& is, Bigint& num) {

		std::string input;

		is >> input;

		num = Bigint(input);

		return is;

	}
	
};

void main() {

	Bigint a("123456789");
	Bigint b("987654321");

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;

	Bigint c("123456789");
	Bigint d("123456789");
	Bigint e("222222222");
	std::cout << "c == d: " << (c == d) << std::endl;

}
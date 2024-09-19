#include "Matrix.hpp"
#include <iostream>

namespace dg {
	// вопрос на счет этого : row(row), col(col) и приватность
	Matrix::Matrix(int row, int col) : row(row), col(col) { // Конструктор по умолчанию

		data = new int* [row];

		for (int N = 0; N < row; N++) {

			data[N] = new int[col];

			for (int M = 0; M < col; M++) {

				data[N][M] = 0;

			}

		}
		std::cout << "Constr" << std::endl;
	}

	Matrix::Matrix(const Matrix& other) : row(other.row), col(other.col) { // Конструктор копирования

		data = new int* [row];

		for (int N = 0; N < row; N++) {

			data[N] = new int[col];

			for (int M = 0; M < col; M++) {

				data[N][M] = other.data[N][M];

			}

		}
		std::cout << "Copy" << std::endl;
	}

	Matrix Matrix::operator=(const Matrix& other) { // Оператор присваивания

		if (this != &other) {

			for (int N = 0; N < row; N++) {

				delete data[N];

			}

			delete data;

			row = other.row;
			col = other.col;

			data = new int* [row];

			for (int N = 0; N < row; N++) {

				data[N] = new int[col];

				for (int M = 0; M < col; M++) {

					data[N][M] = other.data[N][M];

				}

			}

		}
		std::cout << "Copyass" << std::endl;
		return *this;

	}

	Matrix::~Matrix() { // Деструктор

		for (int N = 0; N < row; N++) {

			delete data[N];

		}

		delete data;
		std::cout << "Destr" << std::endl;
	}

	void Matrix::print() {

		for (int N = 0; N < row; N++) {

			for (int M = 0; M < col; M++) {

				std::cout << data[N][M] << ' ' << std::endl;

			}

		}

	}

}
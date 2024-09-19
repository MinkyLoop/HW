#include <iostream>

template <typename T, int N, int M>
class Matrix {

	T data[N][M];

  public:

	Matrix() {

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				data[i][j] = T();

			}

		}

	}

	Matrix(const Matrix& other) {

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				data[i][j] = other.data[i][j];

			}

		}

	}

	Matrix& operator=(const Matrix& other) {

		if (this != &other) {
			
			for (int i = 0; i < N; ++i) {

				for (int j = 0; j < M; ++j) {

					data[i][j] = other.data[i][j];

				}

			}

		}

		return *this;

	}

	~Matrix() { std::cout << "destr" << std::endl; };

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& matrix) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				os << matrix.data[i][j] << ' ';

			}

			os << std::endl;

		}
		
		return os;

	}

	friend std::istream& operator>>(std::istream& is, Matrix<T, N, M>& matrix) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				is >> matrix.data[i][j];

			}

		}

		return is;

	}

	Matrix operator+(const Matrix& other) const {

		Matrix result;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				result.data[i][j] = data[i][j] + other.data[i][j];

			}

		}

		return result;

	}

	Matrix& operator+=(const Matrix& other) {

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				data[i][j] += other.data[i][j];

			}

		}

		return *this;

	}

	template <int P>
	Matrix<T, N, P> operator*(Matrix<T, M, P>& other) const {

		Matrix<T, N, P> result;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < P; ++j) {

				result.setElement(i, j, 0);//data[i][j] = 0;

				for (int k = 0; k < M; ++k) {

					result.setElement(i, j, data[i][k] * other.getElement(k, j) + result.getElement(i, j));// += data[i][k] * other.getElement(k, j);

				}

			}

		}

		return result;

	}

	template <int P>
	Matrix<T, N, P>& operator*=(Matrix<T, P, P>& other) {
		
		*this = *this * other;
		
		return *this;

	}

	Matrix& operator++() {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				data[i][j]++;

			}

		}

		return *this;

	};

	T determinant() {
		
		if (N != M) {

			std::cerr << "Определитель определен только для квадратных матриц." << std::endl;
			return 0;

		}

		T det = 1;

		for (int i = 0; i < N; ++i) {
			
			int nonzeroRow = -1;

			for (int j = i; j < N; ++j) {

				if (data[j][i] != 0) {

					nonzeroRow = j;
					break;

				}
			}

			if (nonzeroRow == -1) {

				return 0;

			}

			if (nonzeroRow != i) {

				for (int j = 0; j < M; ++j) {

					std::swap(data[i][j], data[nonzeroRow][j]);

				}

				det = -det;
			
			}

			for (int j = i + 1; j < N; ++j) {

				T ratio = data[j][i] / data[i][i];

				for (int k = i; k < M; ++k) {

					data[j][k] -= ratio * data[i][k];

				}

			}

			det *= data[i][i];
		}

		return det;

	}

	T getElement(int i, int j) {

		if (i < 0 || i >= N || j < 0 || j >= M) {

			throw std::out_of_range("Index out of range");

		}

		return data[i][j];

	}

	void setElement(int i, int j, T value) {

		if (i < 0 || i >= N || j < 0 || j >= M) {

			throw std::out_of_range("Index out of range");

		}

		data[i][j] = value;

	}


};

void main() {

	Matrix<int, 3, 2> mat1;
	Matrix<int, 2, 2> mat2;
	Matrix<int, 4, 1> mat3;
	Matrix<int, 1, 4> mat4;
	Matrix<int, 4, 4> mat5;
	Matrix<int, 4, 4> mat6;
	

	std::cin >> mat1;
	std::cin >> mat2;
	std::cin >> mat3;
	std::cin >> mat4;
	std::cin >> mat6;
	std::cout << mat1.determinant() << std::endl;
	mat1 *= mat2;

	mat5 = mat3 * mat4;

	std::cout << mat1;
	std::cout << mat5;

	mat5 += mat6;

	std::cout << mat5;

	std::cout << mat5.determinant() << std::endl;


}
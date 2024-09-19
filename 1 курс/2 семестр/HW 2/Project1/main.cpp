#include "Matrix.hpp"
#include <iostream>

void main() {

	dg::Matrix m1(3, 4);
	//m1.print();
	std::cout << std::endl;

	dg::Matrix m2 = m1;
	//m2.print();
	std::cout << std::endl;

	dg::Matrix m3(5, 5);
	//m3.print();
	std::cout << std::endl;
	m3 = m2;
	//m3.print();

}

#include <iostream>
#include "Sphere.hpp"

void main() {

	mt::Sphere c1(5);

	std::cout << "Volume: " << c1.Volume() << std::endl;
	std::cout << "Surface Area: " << c1.SurfaceArea() << std::endl;

}
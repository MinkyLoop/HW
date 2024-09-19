#include "sphere.hpp"
#include <cmath>

#define M_PI 3.14159265358979323846

namespace mt {

    float Sphere::Volume() {

        return (pow(m_r, 3) * 4 * M_PI) / 3;

    }

    float Sphere::SurfaceArea() {

        return pow(m_r, 2) * 4 * M_PI;

    }

    Sphere::Sphere(float r) {

        m_r = r;

    }

    Sphere::~Sphere() {

        // default

    }

}

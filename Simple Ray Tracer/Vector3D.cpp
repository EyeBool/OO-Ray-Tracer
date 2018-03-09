#include "Vector3D.h"
#include <cmath>

// constructors

Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0) {}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3D::Vector3D(const Vector3D& vector3D) : x(vector3D.x), y(vector3D.y), z(vector3D.z) {}

// operators

Vector3D& Vector3D::operator=(const Vector3D& vector3D) {
	x = vector3D.x;
	y = vector3D.y;
	z = vector3D.z;
	return *this;
}

bool Vector3D::operator==(const Vector3D& vector3D) const {
	return (x == vector3D.x) && (y == vector3D.y) && (z == vector3D.z);
}

// instance methods

double Vector3D::length() const {
	return std::sqrt(x * x + y * y + z * z);
}

double Vector3D::lengthSquared() const {
	return x * x + y * y + z * z;
}

Vector3D Vector3D::unitVector() const {
	if (x == 0.0 && y == 0.0 && z == 0.0)
		return Vector3D();

	return (1 / length()) * Vector3D(x, y, z);
}

// friend methods

Vector3D operator*(double scalar, const Vector3D& vector3D) {
	return Vector3D(scalar * vector3D.x, scalar * vector3D.y, scalar * vector3D.z);
}

Vector3D operator+(const Vector3D& vector3D1, const Vector3D& vector3D2) {
	return Vector3D(vector3D1.x + vector3D2.x, vector3D1.y + vector3D2.y, vector3D1.z + vector3D2.z);
}

Vector3D operator-(const Vector3D& vector3D1, const Vector3D& vector3D2) {
	return Vector3D(vector3D1.x - vector3D2.x, vector3D1.y - vector3D2.y, vector3D1.z - vector3D2.z);
}

double dotProduct(const Vector3D& vector3D1, const Vector3D& vector3D2) {
	return vector3D1.x * vector3D2.x + vector3D1.y * vector3D2.y + vector3D1.z * vector3D2.z;
}

 Vector3D crossProduct(const Vector3D& vector3D1, const Vector3D& vector3D2) {
	Vector3D product;

	product.x = vector3D1.y * vector3D2.z - vector3D1.z * vector3D2.y;
	product.y = vector3D1.z * vector3D2.x - vector3D1.x * vector3D2.z;
	product.z = vector3D1.x * vector3D2.y - vector3D1.y - vector3D2.x;

	return product;
}
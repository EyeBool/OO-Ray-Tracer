#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
	double x, y, z;

	// constructors
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const Vector3D& vector3D);

	// operators
	Vector3D& operator=(const Vector3D& vector3D);
	bool operator==(const Vector3D& vector3D);

	// instance methods
	double length();
	double lengthSquared();
	Vector3D unitVector();

	// friend methods
	friend Vector3D operator*(double scalar, const Vector3D& vector3D);
	friend Vector3D operator+(const Vector3D& vector3D1, const Vector3D& vector3D2);
	friend Vector3D operator-(const Vector3D& vector3D1, const Vector3D& vector3D2);
	friend double dotProduct(const Vector3D& vector3D1, const Vector3D& vector3D2);
	friend Vector3D crossProduct(const Vector3D& vector3D1, const Vector3D& vector3D2);
};

#endif
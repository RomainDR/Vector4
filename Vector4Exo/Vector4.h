#pragma once
#include <ostream>
#include <string>

class Vector4
{
#pragma region f/p
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;

	float magnitude = 0;
#pragma endregion f/p

#pragma region constructor
public:
	Vector4(float _x, float _y, float _z = 0, float _w = 0);
#pragma endregion constructor

#pragma region methods
public:
	void Set(float _x, float _y, float _z, float _w);
	void Normalize();
	Vector4* Abs(); //retourne les valeurs absolu de x,y,z et w  //ok 
	Vector4& Add(float _x = 0, float _y = 0, float _z = 0, float _w = 0); //ok
	float Magnitude(); //retourne racine carré de (x*x + y*y + z*z + y*y)
	float Length(); // magnitude
	float LengthSquared(); //racine carrée de magnitude
	std::string ToString();

	static Vector4* Clamp(Vector4* _current, Vector4* _min, Vector4* _max); //return min si current < ; return max si current > ; return current //Ok
	static Vector4* Min(Vector4* _vector, Vector4* _other); //ok
	static Vector4* Max(Vector4* _vector, Vector4* _other); //ok
	static Vector4* Lerp(Vector4* _a, Vector4* _b, float _t);
	static Vector4* LerpUnclamped(Vector4* _a, Vector4* _b, float _t);
	static float Dot(Vector4* _v1, Vector4* _v2); //produit des deux vector
	static float Distance(Vector4* _v1, Vector4* _v2);

#pragma endregion methods

#pragma region operator
public:
	Vector4 operator+(const Vector4& _vector1);
	Vector4& operator+=(const Vector4& _vector);
	Vector4 operator-(const Vector4& _vector);
	Vector4& operator-=(const Vector4& _vector);
	Vector4 operator*(const Vector4& _vector);
	Vector4 operator*(const float& _value);
	Vector4& operator*=(const Vector4& _vector);
	Vector4 operator/(const Vector4& _vector);
	Vector4& operator/=(const Vector4& _vector);
	bool operator>(const Vector4& _vector);
	bool operator>=(const Vector4& _vector);
	bool operator<(const Vector4& _vector);
	bool operator<=(const Vector4& _vector);
	bool operator==(const Vector4& _vector);
	Vector4& operator=(const Vector4& _vector);

	friend std::ostream& operator<<(std::ostream& os, const Vector4* _vector);

#pragma endregion operator
};


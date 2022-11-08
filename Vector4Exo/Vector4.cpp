#include "Vector4.h"
#include <math.h>


Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
	magnitude = std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
}
#pragma region methods
void Vector4::Set(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}
Vector4* Vector4::Abs()
{
	float _x = x;
	float _y = y;
	float _z = z;
	float _w = w;
	try {
		std::string _str = "";
		if (_x < 0.0f) {
			_str = std::to_string(_x);
			_x = std::stof(_str.substr(1, _str.npos));
		}

		if ( _y < 0.0f) {
			_str = std::to_string(_y);
			_y = std::stof(_str.substr(1, _str.npos));
		}
		if (_z < 0.0f) {
			_str = std::to_string(_z);
			_z = std::stof(_str.substr(1, _str.npos));
		}

		if (_w < 0.0f) {
			_str = std::to_string(_w);
			_w = std::stof(_str.substr(1, _str.npos));
		}
		return new Vector4(_x, _y, _z, _w);
	}
	catch (std::exception e) {
		return new Vector4(0, 0, 0, 0);
	}
}

Vector4& Vector4::Add(float _x, float _y, float _z, float _w)
{
	x += _x;
	y += _y;
	z += _z;
	w += _w;
	return *this;
}

Vector4* Vector4::Clamp(Vector4* _current, Vector4* _min, Vector4* _max)
{	
	return _current > _max ? _max : (_current < _min ? _min : _current);
}

Vector4* Vector4::Min(Vector4* _vector, Vector4* _other)
{
	float _minX = 0;
	float _minY = 0;
	float _minZ = 0;
	float _minW = 0;

	_minX = _vector->x < _other->x ? _vector->x : _other->x;
	_minY = _vector->y < _other->y ? _vector->y : _other->y;
	_minZ = _vector->z < _other->z ? _vector->z : _other->z;
	_minW = _vector->w < _other->w ? _vector->w : _other->w;

	return new Vector4(_minX, _minY, _minZ, _minW);


}

Vector4* Vector4::Max(Vector4* _vector, Vector4* _other)
{

	float _minX = 0;
	float _minY = 0;
	float _minZ = 0;
	float _minW = 0;

	_minX = _vector->x > _other->x ? _vector->x : _other->x;
	_minY = _vector->y > _other->y ? _vector->y : _other->y;
	_minZ = _vector->z > _other->z ? _vector->z : _other->z;
	_minW = _vector->w > _other->w ? _vector->w : _other->w;

	return new Vector4(_minX, _minY, _minZ, _minW);
}

Vector4* Vector4::Lerp(Vector4* _a, Vector4* _b, float _t)
{
	_t = _t > 1.0f ? 1.0f : _t < 0.0f ? 0.0f : _t;
	Vector4 _res = *_b - *_a;
	Vector4 _r = *_a + _res;

	return  new Vector4(_r * _t);
}

Vector4* Vector4::LerpUnclamped(Vector4* _a, Vector4* _b, float _t)
{
	Vector4 _res = *_b - *_a;
	Vector4 _r = *_a + _res;

	return  new Vector4(_r * _t);
}


float Vector4::Dot(Vector4* _v1, Vector4* _v2)
{
	Vector4 _res = *_v1 * *_v2;
	return _res.x + _res.y + _res.z + _res.w;
}

float Vector4::Distance(Vector4* _v1, Vector4* _v2)
{
	Vector4 _res = *_v1 - *_v2;
	return _res.Magnitude();
}

void Vector4::Normalize()
{
	float length = Length();
	x = x / length;
	y = y / length;
	z = z / length;
	w = w / length;
	magnitude = std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
}

std::string Vector4::ToString()
{
	return "Vector4 = {" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + "}";
}

float Vector4::Magnitude()
{
	return magnitude;
}

float Vector4::Length()
{
	return Magnitude();
}

float Vector4::LengthSquared()
{
	return std::sqrt(Length());
}

#pragma endregion methods

#pragma region operator

std::ostream& operator<<(std::ostream& os, const Vector4* _vector)
{
	os << "Vector4 = {" << _vector->x << ", " << _vector->y << ", " << _vector->z << ", " << _vector->w << "}";
	return os;
}

Vector4& Vector4::operator=(const Vector4& _vector)
{
	x = _vector.x;
	y = _vector.y;
	z = _vector.z;
	w = _vector.w;
	return *this;
}


Vector4 Vector4::operator+(const Vector4& _vector1)
{
	float _x = _vector1.x + x;
	float _y = _vector1.y + y;
	float _z = _vector1.z + z;
	float _w = _vector1.w + w;
	return Vector4(_x, _y, _z, _w);
}

Vector4& Vector4::operator+=(const Vector4& _vector)
{
	x += _vector.x;
	y += _vector.y;
	z += _vector.z;
	w += _vector.w;
	return *this;
}

Vector4 Vector4::operator-(const Vector4& _vector)
{
	float _x = _vector.x - x;
	float _y = _vector.y - y;
	float _z = _vector.z - z;
	float _w = _vector.w - w;
	return Vector4(_x, _y, _z, _w);
}


Vector4& Vector4::operator-=(const Vector4& _vector)
{
	x -= _vector.x;
	y -= _vector.y;
	z -= _vector.z;
	w -= _vector.w;
	return *this;
}

Vector4 Vector4::operator*(const Vector4& _vector)
{
	float _x = _vector.x * x;
	float _y = _vector.y * y;
	float _z = _vector.z * z;
	float _w = _vector.w * w;
	return Vector4(_x, _y, _z, _w);
}
Vector4 Vector4::operator*(const float& _value)
{
	x *= _value;
	y *= _value;
	z *= _value;
	w *= _value;
	return *this;
}
Vector4& Vector4::operator*=(const Vector4& _vector)
{
	x *= _vector.x;
	y *= _vector.y;
	z *= _vector.z;
	w *= _vector.w;
	return *this;
}

Vector4 Vector4::operator/(const Vector4& _vector)
{
	float _x = x / _vector.x;
	float _y = y / _vector.y;
	float _z = z / _vector.z;
	float _w = w / _vector.w;
	return Vector4(_x, _y, _z, _w);
}

Vector4& Vector4::operator/=(const Vector4& _vector)
{
	x /= _vector.x;
	y /= _vector.y;
	z /= _vector.z;
	w /= _vector.w;
	return *this;
}


bool Vector4::operator>(const Vector4& _vector)
{
	float _x = _vector.x;
	float _y = _vector.y;
	float _z= _vector.z;
	float _w = _vector.w;
	return _x > x || _y > y || _z > z || _w > w;
}

bool Vector4::operator>=(const Vector4& _vector)
{
	float _x = _vector.x;
	float _y = _vector.y;
	float _z = _vector.z;
	float _w = _vector.w;
	return _x >= x || _y >= y || _z >= z || _w >= w;
}

bool Vector4::operator<(const Vector4& _vector)
{
	float _x = _vector.x;
	float _y = _vector.y;
	float _z = _vector.z;
	float _w = _vector.w;
	return _x = x || _y < y || _z < z || _w < w;
}

bool Vector4::operator<=(const Vector4& _vector)
{
	float _x = _vector.x;
	float _y = _vector.y;
	float _z = _vector.z;
	float _w = _vector.w;
	return _x <= x || _y <= y || _z <= z || _w <= w;
}

bool Vector4::operator==(const Vector4& _vector)
{
	float _x = _vector.x;
	float _y = _vector.y;
	float _z = _vector.z;
	float _w = _vector.w;
	return _x == x || _y == y || _z == z || _w == w;
}
#pragma endregion operator

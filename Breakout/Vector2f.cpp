#include "Vector2f.h"
#include <cmath>

namespace breakout
{
	Vector2f::Vector2f(const float x, const float y) : x(x), y(y) { }
	Vector2f::Vector2f(const Vector2f& vec) : Vector2f(vec.x, vec.y) { }
	float Vector2f::getDot(const Vector2f vec) const
	{
		return x * vec.x + y * vec.y;
	}
	float Vector2f::getLength() const
	{
		return std::sqrtf(x * x + y * y);
	}
	void Vector2f::normalize()
	{
		float length = getLength();
		if (length != 0.0f)
		{
			x /= length;
			y /= length;
		}
	}
	void Vector2f::operator=(const Vector2f vec)
	{
		x = vec.x;
		y = vec.y;
	}
	void Vector2f::operator+=(const Vector2f vec)
	{
		x += vec.x;
		y += vec.y;
	}
	void Vector2f::operator-=(const Vector2f vec)
	{
		x -= vec.x;
		y -= vec.y;
	}
	void Vector2f::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
	}
	Vector2f Vector2f::getNormalized() const
	{
		float length = getLength();
		if (length != 0.0f)
		{
			return Vector2f(x / length, y / length);
		}
		return Vector2f();
	}
	Vector2f Vector2f::operator+(const Vector2f& vec) const
	{
		return Vector2f(x + vec.x, y + vec.y);
	}
	Vector2f Vector2f::operator-(const Vector2f& vec) const
	{
		return Vector2f(x - vec.x, y - vec.y);
	}
	Vector2f Vector2f::operator*(const float scalar) const
	{
		return Vector2f(x * scalar, y * scalar);
	}
	Vector2f operator*(float scalar, const Vector2f& vec)
	{
		return Vector2f(vec.x * scalar, vec.y * scalar);
	}
	std::istream& operator>>(std::istream& inStream, Vector2f& vec)
	{
		std::cout << "Enter x: ";
		inStream >> vec.x;
		std::cout << "Enter y: ";
		inStream >> vec.y;
		return inStream;
	}
	std::ostream& operator<<(std::ostream& outStream, const Vector2f& vec)
	{
		outStream << "[ " << vec.x << " , " << vec.y << " ]";
		return outStream;
	}
}

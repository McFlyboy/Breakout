#ifndef VECTOR2F
#define VECTOR2F
#include <iostream>

namespace breakout
{
	class Vector2f
	{
	public:
		float x, y;
		Vector2f(const float x = 0.0f, const float y = 0.0f);
		Vector2f(const Vector2f& vec);
		float getDot(const Vector2f& vec) const;
		float getLength() const;
		void normalize();
		void operator=(const Vector2f& vec);
		void operator+=(const Vector2f& vec);
		void operator-=(const Vector2f& vec);
		void operator*=(const float scalar);
		Vector2f getNormalized() const;
		Vector2f operator+(const Vector2f& vec) const;
		Vector2f operator-(const Vector2f& vec) const;
		Vector2f operator*(const float scalar) const;
		friend Vector2f operator*(float scalar, const Vector2f& vec);
		friend std::istream& operator>>(std::istream& inStream, Vector2f& vec);
		friend std::ostream& operator<<(std::ostream& outStream, const Vector2f& vec);
	};
}
#endif

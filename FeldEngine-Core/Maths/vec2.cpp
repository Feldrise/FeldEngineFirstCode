#include "vec2.h"

namespace Fd {
	namespace Maths {
		vec2::vec2() : x(0.0f), y(0.0f)
		{
		}
		vec2::vec2(const float & x, const float & y)
		{
			this->x = x;
			this->y = y;
		}
		vec2 & vec2::add(const vec2 & other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2 & vec2::substract(const vec2 & other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2 & vec2::multiply(const vec2 & other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2 & vec2::divide(const vec2 & other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		bool vec2::operator==(const vec2 & other)
		{
			return x == other.x && y == other.y;
		}

		bool vec2::operator!=(const vec2 & other)
		{
			return !(*this == other);
		}

		vec2 & vec2::operator+=(const vec2 & other)
		{
			return add(other);
		}

		vec2 & vec2::operator-=(const vec2 & other)
		{
			return substract(other);
		}

		vec2 & vec2::operator*=(const vec2 & other)
		{
			return multiply(other);
		}

		vec2 & vec2::operator/=(const vec2 & other)
		{
			return divide(other);
		}
		vec2 & operator+(vec2 left, const vec2 & right)
		{
			return left.add(right);
		}

		vec2 & operator-(vec2 left, const vec2 & right)
		{
			return left.substract(right);
		}

		vec2 & operator*(vec2 left, const vec2 & right)
		{
			return left.multiply(right);
		}

		vec2 & operator/(vec2 left, const vec2 & right)
		{
			return left.divide(right);
		}
		std::ostream & operator<<(std::ostream & stream, const vec2 & vector)
		{
			stream << "vec2 : (" << vector.x << ", " << vector.y << ")";
			return stream;
		}
	}
}
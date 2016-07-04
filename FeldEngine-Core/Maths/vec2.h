#pragma once

#include <iostream>

namespace Fd {
	namespace Maths {

		template <typename T>
		struct vec2
		{
			T x{};
			T y{};

			vec2() = default;
			vec2(const T& x, const T& y) {
				this->x = x;
				this->y = y;
			}


			vec2& add(const vec2& other) {
				x += other.x;
				y += other.y;

				return *this;
			}
			vec2& substract(const vec2& other) {
				x -= other.x;
				y -= other.y;

				return *this;
			}
			vec2& multiply(const vec2& other) {
				x *= other.x;
				y *= other.y;

				return *this;
			}
			vec2& divide(const vec2& other) {
				x /= other.x;
				y /= other.y;

				return *this;
			}

			friend vec2 operator+(vec2 left, const vec2& right) {
				return left.add(right);
			}
			friend vec2 operator-(vec2 left, const vec2& right) {
				return left.substract(right);
			}
			friend vec2 operator*(vec2 left, const vec2& right) {
				return left.multiply(right);
			}
			friend vec2 operator/(vec2 left, const vec2& right) {
				return left.divide(right);
			}

			bool operator==(const vec2& other) {
				return x == other.x && y == other.y;
			}
			bool operator!=(const vec2& other) {
				return !(*this == other);
			}

			vec2& operator+=(const vec2& other) {
				return add(other);
			}
			vec2& operator-=(const vec2& other) {
				return substract(other);
			}
			vec2& operator*=(const vec2& other) {
				return multiply(other);
			}
			vec2& operator/=(const vec2& other) {
				return divide(other);
			}

			friend std::ostream& operator<< (std::ostream& stream, const vec2& vector) {
				stream << "vec2 : (" << vector.x << ", " << vector.y << ")";
				return stream;
			}
		};
	}
}
#pragma once

#include <iostream>

namespace Fd {
	namespace Maths {

		template <typename T>
		struct Vector2
		{
			T x{};
			T y{};

			Vector2() = default;
			Vector2(const T& x, const T& y) {
				this->x = x;
				this->y = y;
			}


			Vector2& add(const Vector2<T>& other) {
				x += other.x;
				y += other.y;

				return *this;
			}
			Vector2& substract(const Vector2<T>& other) {
				x -= other.x;
				y -= other.y;

				return *this;
			}
			Vector2& multiply(const Vector2<T>& other) {
				x *= other.x;
				y *= other.y;

				return *this;
			}
			Vector2& divide(const Vector2<T>& other) {
				x /= other.x;
				y /= other.y;

				return *this;
			}

			friend Vector2 operator+(Vector2<T> left, const Vector2<T>& right) {
				return left.add(right);
			}
			friend Vector2 operator-(Vector2<T> left, const Vector2<T>& right) {
				return left.substract(right);
			}
			friend Vector2 operator*(Vector2<T> left, const Vector2<T>& right) {
				return left.multiply(right);
			}
			friend Vector2 operator/(Vector2<T> left, const Vector2<T>& right) {
				return left.divide(right);
			}

			bool operator==(const Vector2<T>& other) {
				return x == other.x && y == other.y;
			}
			bool operator!=(const Vector2<T>& other) {
				return !(*this == other);
			}

			Vector2& operator+=(const Vector2<T>& other) {
				return add(other);
			}
			Vector2& operator-=(const Vector2<T>& other) {
				return substract(other);
			}
			Vector2& operator*=(const Vector2<T>& other) {
				return multiply(other);
			}
			Vector2& operator/=(const Vector2<T>& other) {
				return divide(other);
			}

			friend std::ostream& operator<< (std::ostream& stream, const Vector2<T>& vector) {
				stream << "Vector2 : (" << vector.x << ", " << vector.y << ")";
				return stream;
			}
		};
	}
}
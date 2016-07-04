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

		};

		template <typename T>
		Vector2<T> operator+(Vector2<T> left, const Vector2<T>& right) {
			return left.add(right);
		}

		template <typename T>
		Vector2<T> operator-(Vector2<T> left, const Vector2<T>& right) {
			return left.substract(right);
		}

		template <typename T>
		Vector2<T> operator*(Vector2<T> left, const Vector2<T>& right) {
			return left.multiply(right);
		}

		template <typename T>
		Vector2<T> operator/(Vector2<T> left, const Vector2<T>& right) {
			return left.divide(right);
		}

		template <typename T>
		std::ostream& operator<< (std::ostream& stream, const Vector2<T>& vector) {
			stream << "Vector2 : (" << vector.x << ", " << vector.y << ")";
			return stream;
		}

	}
}
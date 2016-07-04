#pragma once

#include <iostream>

namespace Fd {
	namespace Maths {
		template <typename T>
		struct Vector4
		{
			T x{};
			T y{};
			T z{};
			T w{};

			Vector4() = default;
			Vector4(const T& x, const T& y, const T& z, const T& w) {
				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;
			}


			Vector4& add(const Vector4<T>& other) {
				x += other.x;
				y += other.y;
				z += other.z;
				w += other.w;

				return *this;
			}
			Vector4& substract(const Vector4<T>& other) {
				x -= other.x;
				y -= other.y;
				z -= other.z;
				w -= other.w;

				return *this;
			}
			Vector4& multiply(const Vector4<T>& other) {
				x *= other.x;
				y *= other.y;
				z *= other.z;
				w *= other.w;

				return *this;
			}
			Vector4& divide(const Vector4<T>& other) {
				x /= other.x;
				y /= other.y;
				z /= other.z;
				w /= other.w;

				return *this;
			}

			bool operator==(const Vector4<T>& other) {
				return x == other.x && y == other.y && z == other.z && w == other.w;
			}
			bool operator!=(const Vector4<T>& other) {
				return !(*this == other);
			}

			Vector4& operator+=(const Vector4<T>& other) {
				return add(other);
			}
			Vector4& operator-=(const Vector4<T>& other) {
				return substract(other);
			}
			Vector4& operator*=(const Vector4<T>& other) {
				return multiply(other);
			}
			Vector4& operator/=(const Vector4<T>& other) {
				return divide(other);
			}
		};

		template <typename T>
		Vector4<T> operator+(Vector4<T> left, const Vector4<T>& right) {
			return left.add(right);
		}

		template <typename T>
		Vector4<T> operator-(Vector4<T> left, const Vector4<T>& right) {
			return left.substract(right);
		}

		template <typename T>
		Vector4<T> operator*(Vector4<T> left, const Vector4<T>& right) {
			return left.multiply(right);
		}

		template <typename T>
		Vector4<T> operator/(Vector4<T> left, const Vector4<T>& right) {
			return left.divide(right);
		}

		template <typename T>
		std::ostream& operator<< (std::ostream& stream, const Vector4<T>& vector) {
			stream << "Vector4 : (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}
	}
}
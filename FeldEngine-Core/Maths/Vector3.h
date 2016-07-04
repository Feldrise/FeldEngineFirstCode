#pragma once

#include <iostream>

namespace Fd {
	namespace Maths {

		template <typename T>
		struct Vector3
		{
			T x{};
			T y{};
			T z{};

			Vector3() = default;
			Vector3(const T& x, const T& y, const T& z) {
				this->x = x;
				this->y = y;
				this->z = z;
			}


			Vector3& add(const Vector3<T>& other) {
				x += other.x;
				y += other.y;
				z += other.z;

				return *this;
			}
			Vector3& substract(const Vector3<T>& other) {
				x -= other.x;
				y -= other.y;
				z -= other.z;

				return *this;
			}
			Vector3& multiply(const Vector3<T>& other) {
				x *= other.x;
				y *= other.y;
				z *= other.z;

				return *this;
			}
			Vector3& divide(const Vector3<T>& other) {
				x /= other.x;
				y /= other.y;
				z /= other.z;

				return *this;
			}

			friend Vector3 operator+(Vector3<T> left, const Vector3<T>& right) {
				return left.add(right);
			}
			friend Vector3 operator-(Vector3<T> left, const Vector3<T>& right) {
				return left.substract(right);
			}
			friend Vector3 operator*(Vector3<T> left, const Vector3<T>& right) {
				return left.multiply(right);
			}
			friend Vector3 operator/(Vector3<T> left, const Vector3<T>& right) {
				return left.divide(right);
			}

			bool operator==(const Vector3<T>& other) {
				return x == other.x && y == other.y && z == other.z;
			}
			bool operator!=(const Vector3<T>& other) {
				return !(*this == other);
			}

			Vector3& operator+=(const Vector3<T>& other) {
				return add(other);
			}
			Vector3& operator-=(const Vector3<T>& other) {
				return substract(other);
			}
			Vector3& operator*=(const Vector3<T>& other) {
				return multiply(other);
			}
			Vector3& operator/=(const Vector3<T>& other) {
				return divide(other);
			}

			friend std::ostream& operator<< (std::ostream& stream, const Vector3<T>& vector) {
				stream << "Vector3 : (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
				return stream;
			}
		};
	}
}
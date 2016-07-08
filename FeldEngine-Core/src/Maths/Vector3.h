/*
* The MIT License(MIT)
*
* Copyright(c) 2016 Victor DENIS (victordenis01@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions :
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

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
		};

		template <typename T>
		Vector3<T> operator+(Vector3<T> left, const Vector3<T>& right) {
			return left.add(right);
		}

		template <typename T>
		Vector3<T> operator-(Vector3<T> left, const Vector3<T>& right) {
			return left.substract(right);
		}

		template <typename T>
		Vector3<T> operator*(Vector3<T> left, const Vector3<T>& right) {
			return left.multiply(right);
		}

		template <typename T>
		Vector3<T> operator/(Vector3<T> left, const Vector3<T>& right) {
			return left.divide(right);
		}

		template <typename T>
		std::ostream& operator<< (std::ostream& stream, const Vector3<T>& vector) {
			stream << "Vector3 : (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}

		using vec3 = Vector3<float>;
		using vec3i = Vector3<int>;
		using vec3u = Vector3<unsigned>;
		using vec3l = Vector3<long>;
	}
}
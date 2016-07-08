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

		using vec4 = Vector4<float>;
		using vec4i = Vector4<int>;
		using vec4u = Vector4<unsigned>;
		using vec4l = Vector4<long>;
	}
}
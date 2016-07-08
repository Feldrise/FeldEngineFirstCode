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

		using vec2 = Vector2<float>;
		using vec2i = Vector2<int>;
		using vec2u = Vector2<unsigned>;
		using vec2l = Vector2<long>;
	}
}
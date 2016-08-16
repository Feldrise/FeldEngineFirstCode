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

#include <array>
#include "Math.h"

namespace Fd {
	namespace Maths {

		template <typename T>
		struct Matrix4
		{
			union
			{
				//std::array<T, 4 * 4> elements{ 1 };
				float elements[4 * 4];
				std::array<Vector4<T>, 4> columns;
			};
			Matrix4() = default;
			Matrix4(T diagonal) {
				for (int i = 0; i < 4 * 4; i++)
					elements[i] = 0.0f;

				elements[0 + 0 * 4] = diagonal;
				elements[1 + 1 * 4] = diagonal;
				elements[2 + 2 * 4] = diagonal;
				elements[3 + 3 * 4] = diagonal;
			}

			inline static Matrix4 identity() { return Matrix4<T>(1); }

			Matrix4& multiply(const Matrix4<T>& other) {
				float data[16];
				for (int y{ 0 }; y < 4; y++) {
					for (int x{ 0 }; x < 4; x++) {
						T sum = 0;
						for (int e{ 0 }; e < 4; e++) {
							sum += elements[x + e * 4] * other.elements[e + y *4];
						}

						data[x + y * 4] = sum;
					}
				}
				memcpy(elements, data, 4 * 4 * sizeof(float));
				return *this;
			}
			
			static Matrix4 orthographic(T left, T right, T bottom, T top, T near, T far) {
				Matrix4<T> result(1.0f);
				
				result.elements[0 + 0 * 4] = 2.0f / (right - left);
				
				result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
				
				result.elements[2 + 2 * 4] = 2.0f / (near - far);
				
				result.elements[0 + 3 * 4] = (left + right) / (left - right);
				result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
				result.elements[2 + 3 * 4] = (far + near) / (far - near);
				
				return result;

			}
			static Matrix4 perspective(T fov, T aspectRatio, T near, T far) {
				Matrix4<T> result{ 1 };

				T q = 1.0f / static_cast<T>(tan(toRadians(0.5f * fov)));
				T a = q / aspectRatio;

				T b = (near + far) / (near - far);
				T c = (2.0f * near * far) / (near - far);

				result.elements[0 + 0 * 4] = a;
				result.elements[1 + 1 * 4] = q;
				result.elements[2 + 2 * 4] = b;
				result.elements[3 + 2 * 4] = -1;
				result.elements[2 + 3 * 4] = c;

				return result;
			}

			static Matrix4 translation(const Vector3<T>& translation) {
				Matrix4<T> result{ 1 };

				result.elements[0 + 3 * 4] = translation.x;
				result.elements[1 + 3 * 4] = translation.y;
				result.elements[2 + 3 * 4] = translation.z;

				return result;
			}
			static Matrix4 rotation(T angle, const Vector3<T>& axis) {
				Matrix4<T> result{ 1.0f };

				float r = toRadians(angle);
				float c = cos(r);
				float s = sin(r);
				float omc = 1 - c;

				float x = axis.x;
				float y = axis.y;
				float z = axis.z;

				result.elements[0 + 0 * 4] = x * omc + c;
				result.elements[1 + 0 * 4] = y * x * omc + z * s;
				result.elements[2 + 0 * 4] = x * z * omc - y * s;

				result.elements[0 + 1 * 4] = x * y * omc - z * s;
				result.elements[1 + 1 * 4] = y * omc + c;
				result.elements[2 + 1 * 4] = y * z * omc + x * s;

				result.elements[0 + 2 * 4] = x * z * omc + y * s;
				result.elements[1 + 2 * 4] = y * z * omc - x * s;
				result.elements[2 + 2 * 4] = z * omc + c;

				return result;

			}
			static Matrix4 scale(const Vector3<T>& scale) {
				Matrix4<T> result{ 1 };

				result.elements[0 + 3 * 4] = scale.x;
				result.elements[1 + 1 * 4] = scale.y;
				result.elements[2 + 2 * 4] = scale.z;

				return result;
			}

			Matrix4& operator*=(const Matrix4& other) {
				return multiply(other);
			}

		};

		template <typename T>
		Matrix4<T> operator*(Matrix4<T> left, const Matrix4<T>& right) {
			return left.multiply(right);
		}

		using mat4 = Matrix4<float>;
	}
}
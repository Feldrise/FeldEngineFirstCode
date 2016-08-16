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

#include <Windows.h>

namespace Fd {

	class Timer
	{
	public:
		Timer() {
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);

			m_frequency = 1.0 / frequency.QuadPart;

			QueryPerformanceCounter(&m_start);
		}

		void reset() {
			QueryPerformanceCounter(&m_start);
		}

		float elapsed() {
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			
			unsigned _int64 cycles = current.QuadPart - m_start.QuadPart;

			return static_cast<float>(cycles * m_frequency);
		}

	private:
		LARGE_INTEGER m_start;
		double m_frequency;
	};
}
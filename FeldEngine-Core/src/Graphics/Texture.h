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

#include <string>
#include <GL/glew.h>
#include <FreeImage/FreeImage.h>

#include "../Utils/ImageLoad.h"

namespace Fd {
	namespace Graphics {

		class Texture
		{
		public:
			Texture(const std::string& filename);
			~Texture();

			void bind() const;
			void unbind() const;

			inline const unsigned getWidth() const { return m_width; }
			inline const unsigned getHeight() const { return m_height; }
			inline const unsigned getID() const { return m_TID; }

		private:
			GLuint load();
			
			std::string m_filename;
			GLuint m_TID;
			GLsizei m_width;
			GLsizei m_height;
		};

	}
}
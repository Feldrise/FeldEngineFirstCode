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

		private:
			GLuint load();
			
			std::string m_filename;
			GLuint m_TID;
			GLsizei m_width;
			GLsizei m_height;
		};

	}
}
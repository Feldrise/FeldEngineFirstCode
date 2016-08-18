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
#include <iostream>
#include <fstream>

namespace Fd {

	class UtilsFile 
	{
	public:
		static std::string read_file(const std::string& filepath) {
			std::string result{};
			std::string line{};

			std::ifstream file{ filepath };
			if (!file) {
				//TODO: Use a FeldEngine exeption
				std::cout << "Error when you attemp to read " << filepath << std::endl;
				// -> commentaire de Ilearn32: Afficher l'erreur sur std::cout n'est pas le rôle de la fonction read_file(). On peut à la place lancer une exception et éventuellement affiche un message d'erreur sur std::cerr
			}

			while (std::getline(file, line)) {
				result += line + '\n';
			}

			return result;
		} 

	};
}
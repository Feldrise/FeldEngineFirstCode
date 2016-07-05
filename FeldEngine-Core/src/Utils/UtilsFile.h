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
		/*static std::string read_file(const char* filepath) {
			FILE *file = fopen(filepath, "rt");
			fseek(file, 0, SEEK_END);

			const unsigned long lenght = ftell(file);
			char *data = new char[lenght + 1];

			memset(data, 0, lenght + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, lenght, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}*/
	};

	/*std::string read_file(const char* filepath) {
		FILE *file = fopen(filepath, "rt");
		fseek(file, 0, SEEK_END);

		const unsigned long lenght = ftell(file);
		char *data = new char[lenght + 1];

		memset(data, 0, lenght + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, lenght, file);
		fclose(file);

		std::string result(data);
		delete[] data;
		return result;
	} 
	*/
}
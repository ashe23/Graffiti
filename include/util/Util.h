#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace Graffiti
{
	namespace Util
	{
		static std::string ReadFileContent(const std::string& Path)
		{
			std::ifstream ifs(Path);
			std::string content((std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>()));
			return content;
		}
	}
}
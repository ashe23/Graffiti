#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace Graf
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

		static std::string GetEngineDir()
		{
			namespace fs = std::filesystem;
			return fs::current_path().parent_path().u8string() + "/";
		}

		static void PrintErrMsg(const char* Msg)
		{
			std::cerr << Msg << std::endl;
		}
	}
}
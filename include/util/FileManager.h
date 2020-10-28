#pragma once
#include <string>


namespace Graffiti
{
	struct FileManager
	{	
		FileManager() = delete;
		static std::string GetRootDir();
		static std::string GetAssetsDir();
		static std::string GetShadersDir();
	};
}
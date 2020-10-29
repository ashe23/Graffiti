#pragma once
#include <string>


namespace Graffiti
{
	struct FileManager
	{	
	private:
		FileManager() = delete;
	public:
		static std::string GetRootDir();
		static std::string GetAssetsDir();
		static std::string GetShadersDir();
	};
}
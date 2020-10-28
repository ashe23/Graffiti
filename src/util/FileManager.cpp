#include "FileManager.h"

#include <filesystem>

namespace Graffiti
{
	std::string FileManager::GetRootDir()
	{
		namespace fs = std::filesystem;
		auto EngineDir = fs::current_path().parent_path().u8string() + "/";
		if (!std::filesystem::is_directory(EngineDir))
		{
			return fs::current_path().parent_path().parent_path().u8string() + "/";
		}
		return fs::current_path().parent_path().u8string() + "/";
	}
	std::string FileManager::GetAssetsDir()
	{
		return GetRootDir() + "assets/";
	}
	std::string FileManager::GetShadersDir()
	{
		return GetRootDir() + "shaders/";
	}
}
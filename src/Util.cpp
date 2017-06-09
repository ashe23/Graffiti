#include "Util.hpp"

namespace Graffiti {
	// Returns path of file relative to project error if file/folder does not exist
	std::string Util::getPath(const std::string &file_path) {
		using namespace filesystem;

		if (path("../../" + file_path).exists()) {
			return "../../" + file_path;
		}
		else if (path("../" + file_path).exists()) {
			return "../" + file_path;
		}
		std::cerr << file_path.c_str() << " doesnt exist! Aborting." << std::endl;			
		return "";
	}
}
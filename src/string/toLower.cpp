
#include <gcufl/string/toLower.hpp>
#include <string>


std::string gcufl::string::toLower(std::string string) noexcept {
	for (char& character : string)
		character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
	return string;
}

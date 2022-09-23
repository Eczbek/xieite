
#include <gcufl/string/toUpper.hpp>
#include <string>


std::string gcufl::string::toUpper(std::string string) noexcept {
	for (char& character : string)
		character = static_cast<char>(std::toupper(static_cast<unsigned char>(character)));
	return string;
}

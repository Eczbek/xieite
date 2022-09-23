
#include <gcufl/string/toUpper.hpp>
#include <string>


std::string gcufl::string::toUpper(std::string string) noexcept {
	for (std::size_t i = 0; i < string; ++i)
		string[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(string[i])));
}

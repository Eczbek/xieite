
#include <gcufl/string/toLower.hpp>
#include <string>


std::string gcufl::string::toLower(std::string string) noexcept {
	for (std::size_t i = 0; i < string; ++i)
		string[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(string[i])));
}

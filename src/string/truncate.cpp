
#include <cstddef>
#include <gcufl/string/truncate.hpp>
#include <string>

std::string gcufl::string::truncate(const std::string& string, const std::size_t length, const std::string& suffix) noexcept {
	return string.size() > length		
		? string.substr(0, length - suffix.size()) + suffix
		: string;
}

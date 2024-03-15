#ifndef XIEITE_HEADER_STRINGS_TRUNCATE
#	define XIEITE_HEADER_STRINGS_TRUNCATE

#	include <cstddef>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string truncate(const std::string_view string, const std::size_t length, const std::string_view suffix = "") noexcept {
		const std::size_t suffixSize = suffix.size();
		return (string.size() <= length) ? std::string(string) : ((suffixSize > length) ? std::string(suffix.substr(0, length)) : (std::string(string.substr(0, length - suffixSize)) + std::string(suffix)));
	}
}

#endif

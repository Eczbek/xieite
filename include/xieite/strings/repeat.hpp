#ifndef XIEITE_HEADER_STRINGS_REPEAT
#	define XIEITE_HEADER_STRINGS_REPEAT

#	include <cstddef>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string repeat(const std::string_view string, std::size_t count) noexcept {
		std::string result;
		while (count--) {
			result += string;
		}
		return result;
	}
}

#endif

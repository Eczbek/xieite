#ifndef XIEITE_HEADER__STRINGS__REPEAT
#	define XIEITE_HEADER__STRINGS__REPEAT

#	include <cstddef>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	constexpr std::string repeat(const std::string_view string, std::size_t count) noexcept {
		std::string result;
		result.reserve(string.size() * count);
		while (count--) {
			result += string;
		}
		return result;
	}
}

#endif

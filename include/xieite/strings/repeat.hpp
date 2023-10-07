#ifndef XIEITE_HEADER__STRINGS__REPEAT
#	define XIEITE_HEADER__STRINGS__REPEAT

#	include <cstddef>
#	include <string>
#	include <string_view>

namespace xieite::strings {
	[[nodiscard]] constexpr std::string repeat(std::size_t count, const std::string_view string) noexcept {
		std::string result;
		result.reserve(string.size() * count);
		while (count--) {
			result += string;
		}
		return result;
	}
}

#endif

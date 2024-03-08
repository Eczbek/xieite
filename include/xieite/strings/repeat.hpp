#ifndef XIEITE_HEADER_STRINGS_REPEAT
#	define XIEITE_HEADER_STRINGS_REPEAT

#	include <cstddef>
#	include <string>
#	include "../concepts/string.hpp"
#	include "../strings/view.hpp"

namespace xieite::strings {
	template<xieite::concepts::String String = std::string>
	[[nodiscard]] constexpr String repeat(std::size_t count, const xieite::strings::View<String> string) noexcept {
		String result;
		result.reserve(string.size() * count);
		while (count--) {
			result += string;
		}
		return result;
	}
}

#endif

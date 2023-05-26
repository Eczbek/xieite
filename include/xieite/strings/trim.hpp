#ifndef XIEITE_HEADER_STRINGS_TRIM
#	define XIEITE_HEADER_STRINGS_TRIM

#	include <string>
#	include <string_view>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/strings/trimBack.hpp>
#	include <xieite/strings/trimFront.hpp>

namespace xieite::strings {
	[[nodiscard]]
	constexpr std::string trim(const std::string_view string, const char character) noexcept {
		return xieite::strings::trimBack(xieite::strings::trimFront(string, character), character);
	}

	[[nodiscard]]
	constexpr std::string trim(const std::string_view string, const xieite::concepts::RangeOf<char> auto& characters) noexcept {
		return xieite::strings::trimBack(xieite::strings::trimFront(string, characters), characters);
	}
}

#endif

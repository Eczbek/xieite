#ifndef XIEITE_HEADER_STRINGS_LITERALS_STRINGIFY
#	define XIEITE_HEADER_STRINGS_LITERALS_STRINGIFY

#	include <string>
#	include <string_view>

namespace xieite::strings::literals::stringify {
	template<char... characters>
	[[nodiscard]] constexpr std::string operator""_stringify() noexcept {
		return std::string {
			characters...
		};
	}
}

#endif

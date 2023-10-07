#ifndef XIEITE_HEADER__STRINGS__LITERALS__STRINGIFY
#	define XIEITE_HEADER__STRINGS__LITERALS__STRINGIFY

#	include <string>
#	include <string_view>

namespace xieite::strings::literals {
	template<char... characters>
	[[nodiscard]] constexpr std::string operator""_stringify() noexcept {
		return std::string {
			characters...
		};
	}
}

#endif

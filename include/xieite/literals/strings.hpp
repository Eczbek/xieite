#ifndef XIEITE_HEADER__LITERALS__STRINGS
#	define XIEITE_HEADER__LITERALS__STRINGS

#	include <string>
#	include <string_view>

namespace xieite::literals {
	template<char... characters>
	constexpr std::string operator""_s() noexcept {
		return std::string {
			characters...
		};
	}

	template<char... characters>
	constexpr std::string_view operator""_sv() noexcept {
		static constexpr std::string value {
			characters...
		};
		return std::string_view(value);
	}
}

#endif

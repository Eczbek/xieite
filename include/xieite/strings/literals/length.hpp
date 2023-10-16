#ifndef XIEITE_HEADER_STRINGS_LITERALS_LENGTH
#	define XIEITE_HEADER_STRINGS_LITERALS_LENGTH

#	include <cstddef>

namespace xieite::strings::literals {
	template<char... characters>
	[[nodiscard]] constexpr std::size_t operator""_length() noexcept {
		return sizeof...(characters);
	}
}

#endif

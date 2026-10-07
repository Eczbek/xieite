#ifndef DETAIL_XTE_HEADER_CHARS
#	define DETAIL_XTE_HEADER_CHARS
#
#	include "./fundamental_traits.hpp"

namespace xte {
	[[nodiscard]] constexpr bool is_whitespace(xte::is_char auto c) noexcept {
		switch (c) {
			case ' ':
			case '\t':
			case '\n':
			case '\r':
			case '\f':
			case '\v':
				return true;
		}
		return false;
	}

	[[nodiscard]] constexpr bool is_decimal(xte::is_char auto c) noexcept {
		return (c >= '0') && (c <= '9');
	}
}

#endif

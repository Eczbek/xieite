#ifndef DETAIL_XTE_HEADER_DATA_IS_WHITESPACE
#	define DETAIL_XTE_HEADER_DATA_IS_WHITESPACE

namespace xte {
	[[nodiscard]] constexpr bool is_whitespace(char c) noexcept {
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
}

#endif

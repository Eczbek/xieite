#ifndef DETAIL_XTE_HEADER_DATA_QUOTE
#	define DETAIL_XTE_HEADER_DATA_QUOTE
#
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../trait/is_char.hpp"
#	include <algorithm>
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr xte::string quote(xte::is_char auto c) noexcept(false) {
		switch (c) {
			case '\'':
				return "'\\''";
			case '\\':
				return "'\\\\'";
			case '\a':
				return "'\\a'";
			case '\b':
				return "'\\b'";
			case '\f':
				return "'\\f'";
			case '\n':
				return "'\\n'";
			case '\r':
				return "'\\r'";
			case '\t':
				return "'\\t'";
			case '\v':
				return "'\\v'";
		}
		if (xte::string_view(" !\"#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~").contains(c)) {
			return xte::string("'") + c + "'";
		}
		auto n = static_cast<std::make_unsigned_t<decltype(c)>>(c);
		xte::string quoted = "'";
		do {
			quoted += "0123456789ABCDEF"[n % 16];
		} while (n /= 16);
		quoted += "x\\'";
		std::ranges::reverse(quoted);
		return quoted;
	}
}

#endif

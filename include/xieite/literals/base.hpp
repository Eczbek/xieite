#ifndef XIEITE_HEADER__LITERALS__BASE
#	define XIEITE_HEADER__LITERALS__BASE

#	include <string>

namespace xieite::literals {
	template<char... characters>
	[[nodiscard]] constexpr int operator""_base() noexcept {
		static constexpr std::string value {
			characters...
		};
		if constexpr ((value.size() > 1) && (value[0] == '0')) {
			switch (value[1]) {
				case 'x':
				case 'X':
					return 16;
				case 'b':
				case 'B':
					return 2;
			}
			return 8;
		}
		return 10;
	}
}

// Thanks to Che for idea

#endif

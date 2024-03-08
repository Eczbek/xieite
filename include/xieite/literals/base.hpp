#ifndef XIEITE_HEADER_LITERALS_BASE
#	define XIEITE_HEADER_LITERALS_BASE

#	include <array>
#	include <cstddef>

namespace xieite::literals::base {
	template<char... characters>
	[[nodiscard]] constexpr std::size_t operator""_base() noexcept {
		static constexpr std::array<char, sizeof...(characters)> value {
			characters...
		};
		if constexpr ((value.size() > 1) && (value[0] == '0')) {
			switch (value[1]) {
				case 'x': [[fallthrough]];
				case 'X':
					return 16;
				case 'b': [[fallthrough]];
				case 'B':
					return 2;
			}
			return 8;
		}
		return 10;
	}
}

#endif

// Thanks to Che (https://github.com/Tsche) for original idea

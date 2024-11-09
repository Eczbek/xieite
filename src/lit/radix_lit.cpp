export module xieite:radix_lit;

import std;

export namespace xieite::radix_lit {
	template<char... chars>
	[[nodiscard]] constexpr std::size_t operator""_radix() noexcept {
		static constexpr std::array<char, sizeof...(chars)> data = { chars... };
		if constexpr ((data.size() > 1) && (data[0] == '0')) {
			switch (data[1]) {
				case 'x':
				case 'X':
					return 16;
				case 'b':
				case 'B':
					return 2;
				default:
					return 8;
			}
		} else {
			return 10;
		}
	}
}

export module xieite:digit;

import :is_ch;

export namespace xieite {
	template<xieite::is_ch Ch = char>
	[[nodiscard]] constexpr bool digit(Ch c) noexcept {
		return (c >= '0') && (c <= '9');
		// https://eel.is/c++draft/lex.charset#5.sentence-5
	}
}

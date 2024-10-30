export module xieite:digit;

export namespace xieite {
	[[nodiscard]] constexpr bool digit(char c) noexcept {
		return (c >= '0') && (c <= '9');
		// https://eel.is/c++draft/lex.charset#9.sentence-5
	}
}

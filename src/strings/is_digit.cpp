export module xieite:strings.isDigit;

export namespace xieite::strings {
	[[nodiscard]] constexpr bool isDigit(const char character) noexcept {
		return (character >= '0') && (character <= '9');
		// https://eel.is/c++draft/lex.charset#9.sentence-5
	}
}

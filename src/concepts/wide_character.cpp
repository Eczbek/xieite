export module xieite:concepts.WideCharacter;

import std;
import :concepts.SameAsAny;

export namespace xieite::concepts {
	template<typename Type>
	concept WideCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, wchar_t, char16_t, char32_t>;
}

// https://eel.is/c++draft/basic.fundamental#8

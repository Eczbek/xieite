export module xieite:concepts.OrdinaryCharacter;

import std;
import :concepts.SameAsAny;

export namespace xieite::concepts {
	template<typename Type>
	concept OrdinaryCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, signed char, unsigned char>;
}

// https://eel.is/c++draft/basic.fundamental#7

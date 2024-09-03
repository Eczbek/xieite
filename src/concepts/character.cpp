export module xieite:concepts.Character;

import std;
import :concepts.SameAsAny;
import :concepts.WideCharacter;

export namespace xieite::concepts {
	template<typename Type>
	concept Character = xieite::concepts::WideCharacter<Type> || xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, char8_t>;
}

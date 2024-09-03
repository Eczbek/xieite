export module xieite:concepts.NarrowCharacter;

import std;
import :concepts.OrdinaryCharacter;

export namespace xieite::concepts {
	template<typename Type>
	concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Type> || std::same_as<std::remove_cv_t<Type>, char8_t>;
}

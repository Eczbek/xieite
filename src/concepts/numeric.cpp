export module xieite:concepts.Numeric;

import std;
import :concepts.Arithmetic;

export namespace xieite::concepts {
	template<typename Type>
	concept Numeric = xieite::concepts::Arithmetic<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
}

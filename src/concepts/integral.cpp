export module xieite:concepts.Integral;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Integral = std::integral<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
}

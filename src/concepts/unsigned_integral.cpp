export module xieite:concepts.UnsignedIntegral;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept UnsignedIntegral = std::unsigned_integral<Type> && !std::same_as<std::remove_cv_t<Type>, bool>;
}

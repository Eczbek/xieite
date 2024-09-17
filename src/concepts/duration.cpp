export module xieite:concepts.Duration;

import std;
import :concepts.Arithmetic;
import :concepts.Ratio;

namespace {
	template<typename>
	struct IsDuration
	: std::false_type {};

	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Ratio Ratio>
	struct IsDuration<std::chrono::duration<Arithmetic, Ratio>>
	: std::true_type {};
}

export namespace xieite::concepts {
	template<typename Type>
	concept Duration = IsDuration<std::remove_cv_t<Type>>::value;
}

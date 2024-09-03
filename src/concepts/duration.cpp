export module xieite:concepts.Duration;

import std;
import :traits.IsDuration;

export namespace xieite::concepts {
	template<typename Type>
	concept Duration = xieite::traits::IsDuration<std::remove_cv_t<Type>>::value;
}

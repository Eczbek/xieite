export module xieite:concepts.Ratio;

import std;
import :traits.IsRatio;

export namespace xieite::concepts {
	template<typename Type>
	concept Ratio = xieite::traits::IsRatio<std::remove_cv_t<Type>>::value;
}

#ifndef XIEITE_HEADER_CONCEPTS_RATIO
#	define XIEITE_HEADER_CONCEPTS_RATIO

#	include <type_traits>
#	include "../traits/is_ratio.hpp"

namespace xieite::concepts {
	template<typename Type_>
	concept Ratio = xieite::traits::IsRatio<std::remove_cv_t<Type_>>::value;
}

#endif

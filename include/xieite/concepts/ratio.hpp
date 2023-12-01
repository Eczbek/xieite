#ifndef XIEITE_HEADER_CONCEPTS_RATIO
#	define XIEITE_HEADER_CONCEPTS_RATIO

#	include "../traits/is_ratio.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Ratio = xieite::traits::IsRatio<Type>::value;
}

#endif

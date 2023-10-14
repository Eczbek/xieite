#ifndef XIEITE_HEADER_CONCEPTS_RATIO
#	define XIEITE_HEADER_CONCEPTS_RATIO

#	include "../traits/ratio.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Ratio = xieite::traits::Ratio<Type>::value;
}

#endif

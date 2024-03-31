#ifndef XIEITE_HEADER_MATH_PRODUCT
#	define XIEITE_HEADER_MATH_PRODUCT

#	include <concepts>

namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral>
	struct Product {
		UnsignedIntegral lower;
		UnsignedIntegral upper;
	};
}

#endif

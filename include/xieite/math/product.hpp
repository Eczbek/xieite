#ifndef XIEITE_HEADER_MATH_PRODUCT
#	define XIEITE_HEADER_MATH_PRODUCT

#	include <concepts>

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	struct Product {
		UnsignedInteger lower;
		UnsignedInteger upper;

		constexpr Product(const UnsignedInteger lower, const UnsignedInteger upper) noexcept
		: lower(lower), upper(upper) {}
	};
}

#endif

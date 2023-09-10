#ifndef XIEITE_HEADER__MATH__PRODUCT
#	define XIEITE_HEADER__MATH__PRODUCT

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

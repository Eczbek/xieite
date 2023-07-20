#ifndef XIEITE_HEADER_MATH_RESULT
#	define XIEITE_HEADER_MATH_RESULT

#	include <concepts>
#	include <type_traits>
#	include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Numbers>
	using Result = std::conditional_t<(std::same_as<Numbers, long double> || ...), long double, double>;
}

#endif

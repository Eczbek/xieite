#ifndef DETAIL_XTE_HEADER_LIMITS
#	define DETAIL_XTE_HEADER_LIMITS
#
#	include "./aliases.hpp"
#	include "./trait/is_arithmetic.hpp"
#	include "./trait/is_signed_int.hpp"
#	include <limits>

namespace xte {
	template<xte::is_arithmetic arithmetic_type>
	constexpr arithmetic_type highest = std::numeric_limits<arithmetic_type>::max();

	template<xte::is_arithmetic arithmetic_type>
	constexpr arithmetic_type lowest = std::numeric_limits<arithmetic_type>::lowest();

	template<xte::is_arithmetic arithmetic_type>
	constexpr xte::uz width = std::numeric_limits<arithmetic_type>::digits + xte::is_signed_int<arithmetic_type>;
}

#endif

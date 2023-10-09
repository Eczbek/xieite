#ifndef XIEITE_HEADER__TRAITS__IS_RANGE_OF
#	define XIEITE_HEADER__TRAITS__IS_RANGE_OF

#	include "../concepts/range_of.hpp"

namespace xieite::traits {
	template<typename Range, typename Value>
	struct IsRangeOf
	: std::bool_constant<xieite::concepts::RangeOf<Range, Value>> {};
}

#endif

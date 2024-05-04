#ifndef XIEITE_HEADER_TRAITS_IS_RANGE_OF
#	define XIEITE_HEADER_TRAITS_IS_RANGE_OF

#	include "../concepts/range_of.hpp"

namespace xieite::traits {
	template<typename Range_, typename Value_>
	struct IsRangeOf
	: std::bool_constant<xieite::concepts::RangeOf<Range_, Value_>> {};
}

#endif

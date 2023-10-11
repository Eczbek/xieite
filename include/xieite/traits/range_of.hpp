#ifndef XIEITE_HEADER_TRAITS_RANGE_OF
#	define XIEITE_HEADER_TRAITS_RANGE_OF

#	include "../concepts/range_of.hpp"

namespace xieite::traits {
	template<typename Range, typename Value>
	struct RangeOf
	: std::bool_constant<xieite::concepts::RangeOf<Range, Value>> {};
}

#endif

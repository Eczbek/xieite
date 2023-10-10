#pragma once

#include "../concepts/range_of.hpp"

namespace xieite::traits {
	template<typename Range, typename Value>
	struct RangeOf
	: std::bool_constant<xieite::concepts::RangeOf<Range, Value>> {};
}

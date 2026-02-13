#ifndef DETAIL_XTE_HEADER_META_VALUE_AT
#	define DETAIL_XTE_HEADER_META_VALUE_AT
#
#	include "../util/types.hpp"

namespace xte {
	template<xte::uz index, decltype(auto)... xs>
	requires(index < sizeof...(xs))
	constexpr decltype(auto) value_at = xs...[index];
}

#endif

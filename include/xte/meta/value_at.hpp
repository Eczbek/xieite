#ifndef DETAIL_XTE_HEADER_META_VALUE_AT
#	define DETAIL_XTE_HEADER_META_VALUE_AT
#
#	include "../util/numbers.hpp"

namespace xte {
	template<xte::uz index, decltype(auto)... values>
	requires(index < sizeof...(values))
	constexpr decltype(auto) value_at = values...[index];
}

#endif

#ifndef DETAIL_XTE_HEADER_META_TYPE_AT
#	define DETAIL_XTE_HEADER_META_TYPE_AT
#
#	include "../meta/value_at.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<xte::uz index, typename... Ts>
	using type_at = [:xte::value_at<index, ^^Ts...>:];
}

#endif

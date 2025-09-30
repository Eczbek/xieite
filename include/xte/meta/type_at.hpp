#ifndef DETAIL_XTE_HEADER_META_TYPE_AT
#	define DETAIL_XTE_HEADER_META_TYPE_AT
#
#	include "../core/types.hpp"

namespace xte {
	template<xte::uz index, typename... Ts>
	using type_at = Ts...[index];
}

#endif

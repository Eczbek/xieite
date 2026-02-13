#ifndef DETAIL_XTE_HEADER_META_MAKE_SEQ
#	define DETAIL_XTE_HEADER_META_MAKE_SEQ
#
#	include "../meta/seq.hpp"
#	include "../util/types.hpp"
#	include <utility>

namespace xte {
	template<xte::uz size>
	constexpr auto make_seq = ([]<xte::uz... i>(std::index_sequence<i...>) {
		return xte::seq<i...>();
	})(std::make_index_sequence<size>());
}

#endif

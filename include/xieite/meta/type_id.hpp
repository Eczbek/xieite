#ifndef DETAIL_XIEITE_HEADER_META_TYPE_ID
#	define DETAIL_XIEITE_HEADER_META_TYPE_ID
#
#	include <cstddef>
#	include "../meta/state.hpp"

namespace DETAIL_XIEITE::type_id {
	using state = xieite::state<>;
}

namespace xieite {
	template<typename>
	constexpr std::size_t type_id = DETAIL_XIEITE::type_id::state::advance<[] {}>();
}

#endif

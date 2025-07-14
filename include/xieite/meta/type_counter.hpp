#ifndef DETAIL_XIEITE_HEADER_META_TYPE_COUNTER
#	define DETAIL_XIEITE_HEADER_META_TYPE_COUNTER
#
#	include <cstddef>
#	include "../meta/state.hpp"

namespace DETAIL_XIEITE::type_counter {
	inline constexpr xieite::state<> impl;
}

namespace xieite {
	template<typename>
	constexpr std::size_t type_counter = DETAIL_XIEITE::type_counter::impl.advance<[] {}>();
}

#endif

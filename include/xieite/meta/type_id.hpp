#pragma once

#include <cstddef>
#include "../meta/state.hpp"

namespace DETAIL_XIEITE::type_id {
	using state = xieite::state<>;
}

namespace xieite {
	template<typename>
	constexpr std::size_t type_id = DETAIL_XIEITE::type_id::state::advance();
}

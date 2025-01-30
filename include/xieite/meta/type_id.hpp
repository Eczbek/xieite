#pragma once

#include <cstddef>
#include "../meta/state.hpp"

namespace XIEITE_DETAIL::type_id {
	using state = xieite::state<>;
}

namespace xieite {
	template<typename>
	constexpr std::size_t type_id = XIEITE_DETAIL::type_id::state::advance();
}

#pragma once

#include <cstddef>
#include "../meta/state.hpp"

namespace DETAIL_X4::typid {
	using state = x4::state<>;
}

namespace x4 {
	template<typename>
	constexpr std::size_t typid = DETAIL_X4::typid::state::adv();
}

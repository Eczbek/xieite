#pragma once

#include "../ctnr/view_after.hpp"
#include "../ctnr/view_before.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto view_betw(auto&& range, auto&& a, auto&& b)
		XIEITE_ARROW(xieite::view_after(xieite::view_before(XIEITE_FWD(range), XIEITE_FWD(b)), XIEITE_FWD(a)))
}

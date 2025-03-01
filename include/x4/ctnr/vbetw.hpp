#pragma once

#include "../ctnr/vafter.hpp"
#include "../ctnr/vbef.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	[[nodiscard]] constexpr auto vbetw(auto&& range, auto&& a, auto&& b)
		X4AR(x4::vafter(x4::vbef(X4FWD(range), X4FWD(b)), X4FWD(a)))
}

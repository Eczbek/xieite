#pragma once

#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	struct cast {
		[[nodiscard]] constexpr auto operator()(auto&& x)
			XIEITE_ARROW(static_cast<T>(XIEITE_FWD(x)))
	};
}

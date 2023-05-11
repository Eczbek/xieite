#pragma once

#include <xieite/traits/isFunction.hpp>

namespace xieite::concepts {
	template<typename Invocable, typename ResultOfParameters>
	concept Function = xieite::traits::isFunction<Invocable, ResultOfParameters>;
}

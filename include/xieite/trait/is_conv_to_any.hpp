#pragma once

#include "../trait/is_conv_to.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_to_any = (... || xieite::is_conv_to<T, Us>);
}

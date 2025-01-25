#pragma once

#include "../trait/is_conv_from.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_from_any = (... || xieite::is_conv_from<T, Us>);
}

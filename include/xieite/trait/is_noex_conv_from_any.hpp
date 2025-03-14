#pragma once

#include "../trait/is_noex_conv_from.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv_from_any = (... && xieite::is_noex_conv_from<T, Us>);
}

#pragma once

#include "../trait/is_noex_conv.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv_any = (... || xieite::is_noex_conv<T, Us>);
}

#pragma once

#include "../trait/is_base.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_base_any = (... || xieite::is_base<T, Us>);
}

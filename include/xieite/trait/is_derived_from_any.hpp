#pragma once

#include "../trait/is_derived_from.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_derived_from_any = (... || xieite::is_derived_from<T, Us>);
}

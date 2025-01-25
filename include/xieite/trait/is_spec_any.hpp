#pragma once

#include "../trait/is_spec.hpp"

namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec_any = (... || xieite::is_spec<T, Ms>);
}

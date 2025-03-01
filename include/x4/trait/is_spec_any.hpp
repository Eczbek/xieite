#pragma once

#include "../trait/isspec.hpp"

namespace x4 {
	template<typename T, template<typename...> typename... Ms>
	concept isspecany = (... || x4::isspec<T, Ms>);
}

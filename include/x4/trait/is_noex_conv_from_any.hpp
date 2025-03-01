#pragma once

#include "../trait/isnoexconv_from.hpp"

namespace x4 {
	template<typename T, typename... Us>
	concept isnoexconvfromany = (... && x4::isnoexconv_from<T, Us>);
}

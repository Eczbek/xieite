#pragma once

#include "../trait/isnoexconv.hpp"

namespace x4 {
	template<typename T, typename... Us>
	concept isnoexconvfrom = (... && x4::isnoexconv<Us, T>);
}

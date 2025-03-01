#pragma once

#include "../trait/isnoexconv.hpp"

namespace x4 {
	template<typename T, typename... Us>
	concept isnoexconvany = (... || x4::isnoexconv<T, Us>);
}

#pragma once

#include "../trait/isbase.hpp"

namespace x4 {
	template<typename T, typename... Us>
	concept isbaseany = (... || x4::isbase<T, Us>);
}

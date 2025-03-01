#pragma once

#include "../trait/isvreft.hpp"
#include "../trait/isvar.hpp"

namespace x4 {
	template<typename T>
	concept isvarv = x4::isvar<T> && x4::isvreft<T>;
}

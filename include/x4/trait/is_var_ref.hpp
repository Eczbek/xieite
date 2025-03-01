#pragma once

#include "../trait/isrefreft.hpp"
#include "../trait/isvar.hpp"

namespace x4 {
	template<typename T>
	concept isvarref = x4::isvar<T> && x4::isrefreft<T>;
}

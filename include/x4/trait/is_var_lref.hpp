#pragma once

#include "../trait/islrefreft.hpp"
#include "../trait/isvar.hpp"

namespace x4 {
	template<typename T>
	concept isvarlref = x4::isvar<T> && x4::islrefreft<T>;
}

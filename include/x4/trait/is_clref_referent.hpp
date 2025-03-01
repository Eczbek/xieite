#pragma once

#include "../trait/iscreft.hpp"
#include "../trait/islrefreft.hpp"

namespace x4 {
	template<typename T>
	concept isclrefreft = x4::iscreft<T> && x4::islrefreft<T>;
}

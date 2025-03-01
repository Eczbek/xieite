#pragma once

#include "../trait/isclrefreft.hpp"
#include "../trait/iscrrefreft.hpp"

namespace x4 {
	template<typename T>
	concept iscrefreft = x4::isclrefreft<T> || x4::iscrrefreft<T>;
}

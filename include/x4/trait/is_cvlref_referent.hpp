#pragma once

#include "../trait/iscvreft.hpp"
#include "../trait/islrefreft.hpp"

namespace x4 {
	template<typename T>
	concept iscvlrefreft = x4::iscvreft<T> && x4::islrefreft<T>;
}

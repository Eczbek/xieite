#pragma once

#include "../trait/iscvlrefreft.hpp"
#include "../trait/iscvrrefreft.hpp"

namespace x4 {
	template<typename T>
	concept iscvrefreft = x4::iscvlrefreft<T> || x4::iscvrrefreft<T>;
}

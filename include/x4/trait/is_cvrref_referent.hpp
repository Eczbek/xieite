#pragma once

#include "../trait/iscvreft.hpp"
#include "../trait/isrrefreft.hpp"

namespace x4 {
	template<typename T>
	concept iscvrrefreft = x4::iscvreft<T> && x4::isrrefreft<T>;
}

#pragma once

#include "../trait/iscreft.hpp"
#include "../trait/isvreft.hpp"

namespace x4 {
	template<typename T>
	concept iscvreft = x4::iscreft<T> && x4::isvreft<T>;
}

#pragma once

#include "../trait/iscv.hpp"
#include "../trait/isrref.hpp"

namespace x4 {
	template<typename T>
	concept iscvrref = x4::iscv<T> && x4::isrref<T>;
}

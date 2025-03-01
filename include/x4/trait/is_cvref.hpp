#pragma once

#include "../trait/iscvlref.hpp"
#include "../trait/iscvrref.hpp"

namespace x4 {
	template<typename T>
	concept iscvref = x4::iscvlref<T> || x4::iscvrref<T>;
}

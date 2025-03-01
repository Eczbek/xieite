#pragma once

#include "../trait/iscv.hpp"
#include "../trait/islref.hpp"

namespace x4 {
	template<typename T>
	concept iscvlref = x4::iscv<T> && x4::islref<T>;
}

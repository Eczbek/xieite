#pragma once

#include <cstddef>
#include "../trait/isinvoc.hpp"

namespace x4 {
	template<typename T, typename Arg>
	concept ishasher = x4::isinvoc<T, std::size_t(Arg)>;
}

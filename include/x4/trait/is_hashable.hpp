#pragma once

#include <cstddef>
#include <functional>
#include "../trait/isinvoc.hpp"

namespace x4 {
	template<typename T, typename Hasher = std::hash<T>>
	concept ishashable = x4::isinvoc<Hasher, std::size_t(T)>;
}

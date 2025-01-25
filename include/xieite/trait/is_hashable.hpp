#pragma once

#include <cstddef>
#include <functional>
#include "../trait/is_invoc.hpp"

namespace xieite {
	template<typename T, typename Hasher = std::hash<T>>
	concept is_hashable = xieite::is_invoc<Hasher, std::size_t(T)>;
}

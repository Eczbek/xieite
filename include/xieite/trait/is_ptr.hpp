#pragma once

#include <cstddef>
#include <type_traits>
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename T, std::size_t depth = 0>
	concept is_ptr = std::is_pointer_v<xieite::rm_ptr<T, depth>>;
}

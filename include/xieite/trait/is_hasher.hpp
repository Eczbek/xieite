#pragma once

#include <cstddef>
#include "../trait/is_invoc.hpp"

namespace xieite {
	template<typename T, typename Arg>
	concept is_hasher = xieite::is_invoc<T, std::size_t(Arg)>;
}

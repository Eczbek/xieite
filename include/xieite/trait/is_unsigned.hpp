#pragma once

#include <concepts>
#include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_unsigned = std::unsigned_integral<T> && !std::same_as<xieite::rm_cv<T>, bool>;
}

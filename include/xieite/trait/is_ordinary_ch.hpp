#pragma once

#include "../trait/is_same_any.hpp"
#include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_ordinary_ch = xieite::is_same_any<xieite::rm_cv<T>, char, unsigned char, signed char>;
}

// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-2

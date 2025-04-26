#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ORDINARY_CHAR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ORDINARY_CHAR
#
#	include "../trait/is_same_any.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_ordinary_char = xieite::is_same_any<xieite::rm_cv<T>, char, unsigned char, signed char>;
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-2

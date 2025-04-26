#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NARROW_CHAR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NARROW_CHAR
#
#	include <concepts>
#	include "../trait/is_ordinary_char.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_narrow_char = xieite::is_ordinary_char<T> || std::same_as<xieite::rm_cv<T>, char8_t>;
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-3

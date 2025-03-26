#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NARROW_CH
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NARROW_CH
#
#	include <concepts>
#	include "../trait/is_ordinary_ch.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_narrow_ch = xieite::is_ordinary_ch<T> || std::same_as<xieite::rm_cv<T>, char8_t>;
}

#endif

// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-3

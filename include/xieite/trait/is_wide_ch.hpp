#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_WIDE_CH
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_WIDE_CH
#
#	include "../trait/is_same_any.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_wide_ch = xieite::is_same_any<xieite::rm_cv<T>, wchar_t, char16_t, char32_t>;
}

#endif

// I'm certain that a section of the C++ working draft was previously referenced here, but now it's gone and apparently never existed. Oh well.

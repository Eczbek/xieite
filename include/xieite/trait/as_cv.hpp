#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_CV
#
#	include "../pp/arrow.hpp"
#	include "../trait/add_cv.hpp"

namespace xieite {
	constexpr auto as_cv =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::add_cv<T&&>>(x));
}

#endif

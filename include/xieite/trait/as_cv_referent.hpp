#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_CV_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_CV_REFERENT
#
#	include "../pp/arrow.hpp"
#	include "../trait/add_cv_referent.hpp"

namespace xieite {
	constexpr auto as_cv_referent =
		[]<typename T>[[nodiscard]](T&& x) static
			XIEITE_ARROW(const_cast<xieite::add_cv_referent<T&&>>(x));
}

#endif

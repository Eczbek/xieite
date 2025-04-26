#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_CV
#
#	include "../trait/rm_cv.hpp"

namespace xieite {
	inline constexpr auto as_not_cv = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::rm_cv<T&&>>(x);
	};
}

#endif

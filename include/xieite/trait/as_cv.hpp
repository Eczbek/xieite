#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_CV
#
#	include "../trait/add_cv.hpp"

namespace xieite {
	inline constexpr auto as_cv = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::add_cv<T&&>>(x);
	};
}

#endif

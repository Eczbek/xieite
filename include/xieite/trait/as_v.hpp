#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_V
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_V
#
#	include "../trait/add_v.hpp"

namespace xieite {
	inline constexpr auto as_v = []<typename T>[[nodiscard]](T&& x) static noexcept {
		return const_cast<xieite::add_v<T&&>>(x);
	};
}

#endif

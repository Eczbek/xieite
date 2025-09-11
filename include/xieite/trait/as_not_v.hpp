#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_V
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_NOT_V
#
#	include "../trait/rm_v.hpp"

namespace xieite {
	inline constexpr auto as_not_v = []<typename T>[[nodiscard]](T&& x) /* static */ noexcept {
		return const_cast<xieite::rm_v<T&&>>(x);
	};
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=121900

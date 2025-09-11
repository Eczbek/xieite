#ifndef DETAIL_XIEITE_HEADER_TRAIT_AS_C
#	define DETAIL_XIEITE_HEADER_TRAIT_AS_C
#
#	include "../trait/add_c.hpp"

namespace xieite {
	inline constexpr auto as_c = []<typename T>[[nodiscard]](T&& x) /* static */ noexcept {
		return const_cast<xieite::add_c<T&&>>(x);
	};
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=121900

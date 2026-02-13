#ifndef DETAIL_XTE_HEADER_META_FAKE
#	define DETAIL_XTE_HEADER_META_FAKE
#
#	include "../trait/add_rref.hpp"

namespace xte {
	template<typename T>
	[[nodiscard]] xte::add_rref<T> fake() noexcept {
		static_assert(false, "must not be evaluated");
	}
}

#endif

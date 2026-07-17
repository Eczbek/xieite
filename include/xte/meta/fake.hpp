#ifndef DETAIL_XTE_HEADER_META_FAKE
#	define DETAIL_XTE_HEADER_META_FAKE
#
#	include "../trait/add_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	[[nodiscard]] xte::add_rvalue_ref<T> fake() noexcept {
		static_assert(false, "must not be evaluated");
	}
}

#endif

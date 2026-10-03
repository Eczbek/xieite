#ifndef DETAIL_XTE_HEADER_META_FAKE
#	define DETAIL_XTE_HEADER_META_FAKE
#
#	include "../qual_traits.hpp"

namespace xte {
	template<typename type>
	[[nodiscard]] xte::add_rvalue_ref<type> fake() noexcept {
		static_assert(false, "must not be evaluated");
	}
}

#endif

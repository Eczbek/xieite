#ifndef DETAIL_XTE_HEADER_META_DECLARE
#	define DETAIL_XTE_HEADER_META_DECLARE
#
#	include "../trait/add_rref.hpp"

namespace xte {
	template<typename T>
	xte::add_rref<T> declare() noexcept {
		static_assert(false, "must not be evaluated");
	}
}

#endif

#ifndef DETAIL_XIEITE_HEADER_META_COLLAPSE_FWD
#	define DETAIL_XIEITE_HEADER_META_COLLAPSE_FWD
#
#	include "../trait/collapse_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	[[nodiscard]] constexpr decltype(auto) collapse_fwd(U&& x) noexcept {
		return static_cast<xieite::collapse_ref<T, U>>(x);
	}
}

#endif

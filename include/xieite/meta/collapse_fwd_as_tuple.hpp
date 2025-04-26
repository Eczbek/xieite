#ifndef DETAIL_XIEITE_HEADER_META_COLLAPSE_FWD_AS_TUPLE
#	define DETAIL_XIEITE_HEADER_META_COLLAPSE_FWD_AS_TUPLE
#
#	include <tuple>
#	include "../meta/collapse_fwd.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr auto collapse_fwd_as_tuple(auto&&... args) noexcept {
		return std::forward_as_tuple(xieite::collapse_fwd<T>(XIEITE_FWD(args))...);
	}
}

#endif

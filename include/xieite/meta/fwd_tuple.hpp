#ifndef DETAIL_XIEITE_HEADER_META_FWD_TUPLE
#	define DETAIL_XIEITE_HEADER_META_FWD_TUPLE
#
#	include <tuple>
#	include "../pp/fwd.hpp"
#	include "../pp/lift.hpp"
#	include "../trait/is_tuple_like.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto fwd_tuple(xieite::is_tuple_like auto&& x) noexcept {
		return std::apply(XIEITE_LIFT(std::forward_as_tuple), XIEITE_FWD(x));
	}
}

#endif

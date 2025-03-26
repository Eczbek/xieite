#ifndef DETAIL_XIEITE_HEADER_META_FWD_TUPLE
#	define DETAIL_XIEITE_HEADER_META_FWD_TUPLE
#
#	include <tuple>
#	include "../pp/fwd.hpp"
#	include "../pp/lift.hpp"
#	include "../trait/is_tuple_like.hpp"

namespace xieite {
	template<xieite::is_tuple_like Tuple>
	[[nodiscard]] constexpr auto fwd_tuple(Tuple&& x) noexcept {
		return std::apply(XIEITE_LIFT(std::forward_as_tuple), XIEITE_FWD(x));
	}
}

#endif

#ifndef DETAIL_XIEITE_HEADER_META_VALUE
#	define DETAIL_XIEITE_HEADER_META_VALUE
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<decltype(auto) x>
	struct value_id {
		static constexpr decltype(auto) value = x;

		[[nodiscard]] constexpr operator decltype(auto)() const noexcept {
			return x;
		}

		[[nodiscard]] static constexpr decltype(auto) operator()() noexcept {
			return x;
		}

		[[nodiscard]] friend constexpr auto operator<=>(xieite::value_id<x>, auto&& rhs)
			XIEITE_ARROW(x <=> XIEITE_FWD(rhs))

		[[nodiscard]] friend constexpr auto operator==(xieite::value_id<x>, auto&& rhs)
			XIEITE_ARROW(x == XIEITE_FWD(rhs))
	};
}

#endif

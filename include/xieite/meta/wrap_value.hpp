#ifndef DETAIL_XIEITE_HEADER_META_WRAP_VALUE
#	define DETAIL_XIEITE_HEADER_META_WRAP_VALUE
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<decltype(auto) x>
	struct wrap_value {
		static constexpr decltype(auto) value = x;

		[[nodiscard]] explicit(false) constexpr operator decltype(auto)() const noexcept {
			return x;
		}

		[[nodiscard]] static constexpr decltype(auto) operator()() noexcept {
			return x;
		}

		[[nodiscard]] friend constexpr auto operator<=>(xieite::wrap_value<x>, auto&& rhs) XIEITE_ARROW(
			x <=> XIEITE_FWD(rhs)
		)

		[[nodiscard]] friend constexpr auto operator==(xieite::wrap_value<x>, auto&& rhs) XIEITE_ARROW(
			x == XIEITE_FWD(rhs)
		)
	};
}

#endif

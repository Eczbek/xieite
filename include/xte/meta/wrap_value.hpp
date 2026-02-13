#ifndef DETAIL_XTE_HEADER_META_WRAP_VALUE
#	define DETAIL_XTE_HEADER_META_WRAP_VALUE
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"

namespace xte {
	template<decltype(auto) x>
	struct wrap_value {
		static constexpr decltype(auto) value = x;

		[[nodiscard]] explicit(false) constexpr operator decltype(x)() const noexcept {
			return x;
		}

		[[nodiscard]] static constexpr decltype(auto) operator()() noexcept {
			return x;
		}

		[[nodiscard]] friend constexpr auto operator<=>(xte::wrap_value<x>, auto&& rhs) XTE_ARROW(
			x <=> XTE_FWD(rhs)
		)

		[[nodiscard]] friend constexpr auto operator==(xte::wrap_value<x>, auto&& rhs) XTE_ARROW(
			x == XTE_FWD(rhs)
		)
	};
}

#endif

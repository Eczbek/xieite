#ifndef DETAIL_XTE_HEADER_META_WRAP
#	define DETAIL_XTE_HEADER_META_WRAP
#
#	include "../macros.hpp"

namespace xte {
	template<typename arg_type>
	struct wrap_type {
		using type = arg_type;
	};

	template<decltype(auto) x>
	struct wrap_value {
		static constexpr decltype(auto) value = x;

		[[nodiscard]] constexpr explicit(false) operator decltype(x)() const noexcept {
			return x;
		}

		[[nodiscard]] static constexpr decltype(auto) operator()() noexcept {
			return x;
		}

		[[nodiscard]] friend constexpr auto operator<=>(xte::wrap_value<x>, auto&& rhs) XTE_RETURNS(
			x <=> XTE_FWD(rhs)
		)

		[[nodiscard]] friend constexpr auto operator==(xte::wrap_value<x>, auto&& rhs) XTE_RETURNS(
			x == XTE_FWD(rhs)
		)
	};
}

#endif

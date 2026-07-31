#ifndef DETAIL_XTE_HEADER_FUNC_ROTATE_SWAP
#	define DETAIL_XTE_HEADER_FUNC_ROTATE_SWAP
#
#	include "../func/unroll.hpp"
#	include "../trait/is_noex_move_assignable.hpp"
#	include "../trait/is_noex_move_constructible.hpp"
#	include "../util/as_xvalue.hpp"
#	include "../util/number_types.hpp"

namespace xte {
	template<xte::uz distance = 1>
	constexpr void rotate_swap(auto&... args)
	noexcept((... && (xte::is_noex_move_constructible<decltype(args)> && xte::is_noex_move_assignable<decltype(args)>))) {
		if constexpr (static constexpr xte::uz size = sizeof...(args); size && (distance % size)) {
			if constexpr (static constexpr xte::uz mod = distance % size; (mod == 1) || (size % mod)) {
				auto tmp = xte::as_xvalue(args...[0]);
				xte::unroll<(size - 1)>([&]<xte::uz i> {
					args...[i * mod % size] = xte::as_xvalue(args...[(i * mod % size + mod) % size]);
				});
				args...[size - mod] = xte::as_xvalue(tmp);
			} else {
				xte::unroll<mod>([&]<xte::uz i> {
					auto tmp = xte::as_xvalue(args...[i]);
					xte::unroll<(size / mod)>([&]<xte::uz j> {
						args...[i + j * mod] = xte::as_xvalue(args...[(i + j * mod + mod) % size]);
					});
					args...[size - mod + i] = xte::as_xvalue(tmp);
				});
			}
		}
	}
}

#endif

#ifndef DETAIL_XIEITE_HEADER_FN_DISTRIBUTE_ARGS
#	define DETAIL_XIEITE_HEADER_FN_DISTRIBUTE_ARGS
#
#	include <cstddef>
#	include <tuple>
#	include <utility>
#	include "../fn/unroll.hpp"
#	include "../meta/splice_tuple.hpp"
#	include "../meta/subtuple.hpp"
#	include "../meta/tuple_size.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<std::size_t arity>
	constexpr void distribute_args(auto&& fn, auto&&... args) XIEITE_ARROW_RET(
		xieite::unroll<(sizeof...(args) / arity)>([]<std::size_t... i>(const auto& fn, const auto& args_tuple) XIEITE_ARROW(
			(..., (void)std::apply(fn, xieite::subtuple<(i * arity), ((i + 1) * arity)>(std::move(args_tuple))))
		), fn, std::forward_as_tuple(XIEITE_FWD(args)...))
	)

	template<std::size_t arity, std::size_t prev>
	[[nodiscard]] constexpr decltype(auto) distribute_args(auto&& fn, auto&&... args) noexcept(false) {
		return ([]<typename Args>(this auto next, auto&& fn, const Args& args_tuple) -> decltype(auto) {
			if constexpr (xieite::tuple_size<Args> == arity) {
				return std::apply(XIEITE_FWD(fn), args_tuple);
			} else {
				return std::apply(
					fn,
					xieite::splice_tuple<0, (xieite::tuple_size<Args> - (arity - prev))>(
						std::move(args_tuple),
						xieite::unroll<prev>(
							[]<std::size_t... i>(auto next, const auto& fn, const auto& args_tuple) {
								return std::make_tuple(next(
									fn,
									xieite::subtuple<
										((xieite::tuple_size<Args> - (arity - prev)) / prev * i),
										((xieite::tuple_size<Args> - (arity - prev)) / prev * (i + 1))
									>(std::move(args_tuple))
								)...);
							},
							next,
							fn,
							args_tuple
						)
					)
				);
			}
		})(XIEITE_FWD(fn), std::forward_as_tuple(XIEITE_FWD(args)...));
	}
}

#endif

// TODO: Revise

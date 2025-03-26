#ifndef DETAIL_XIEITE_HEADER_FN_DISTR_ARGS
#	define DETAIL_XIEITE_HEADER_FN_DISTR_ARGS
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
	template<std::size_t arity, std::size_t prev = 0>
	constexpr decltype(auto) distr_args(auto&& fn, auto&&... args) noexcept(false) { // TODO: `noexcept` specifier
		return ([]<typename Args>(this auto next, auto&& fn, const Args& args) -> decltype(auto) {
			if constexpr (xieite::tuple_size<Args> == arity) {
				return std::apply(XIEITE_FWD(fn), std::move(args));
			} else if constexpr (prev) {
				return std::apply(
					fn,
					xieite::splice_tuple<0, (xieite::tuple_size<Args> - (arity - prev))>(
						std::move(args),
						xieite::unroll<prev>(
							[]<std::size_t... i>(auto next, const auto& fn, const auto& args) {
								return std::make_tuple(next(
									fn,
									xieite::subtuple<
										((xieite::tuple_size<Args> - (arity - prev)) / prev * i),
										((xieite::tuple_size<Args> - (arity - prev)) / prev * (i + 1))
									>(std::move(args))
								)...);
							},
							next,
							fn,
							args
						)
					)
				);
			} else {
				return xieite::unroll<(xieite::tuple_size<Args> / arity)>(
					[]<std::size_t... i>(const auto& fn, const Args& args) static {
						return (..., std::apply(
							fn,
							xieite::subtuple<(i * arity), ((i + 1) * arity)>(std::move(args))
						));
					},
					fn,
					args
				);
			}
		})(XIEITE_FWD(fn), std::forward_as_tuple(XIEITE_FWD(args)...));
	}
}

#endif

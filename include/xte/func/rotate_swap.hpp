#ifndef DETAIL_XTE_HEADER_FUNC_ROTATE_SWAP
#	define DETAIL_XTE_HEADER_FUNC_ROTATE_SWAP
#
#	include "../func/unroll.hpp"
#	include "../preproc/returns.hpp"
#	include "../util/as_xvalue.hpp"
#	include "../util/assign.hpp"
#	include "../util/number_types.hpp"

namespace xte {
	template<xte::uz distance = 1>
	constexpr auto rotate_swap(auto&... args) XTE_RETURNS_IF(
		(sizeof...(args) && !!(distance % sizeof...(args))),
		(void)([]<xte::uz size = sizeof...(args), xte::uz mod = (distance % size)>(auto&... args) XTE_RETURNS_CHOOSE(
			((mod == 1) || (size % mod)),
			([](auto tmp, auto&... args) XTE_RETURNS(
				xte::unroll<(size - 1)>([]<xte::uz i>(auto&... args) XTE_RETURNS(
					xte::assign(args...[i * mod % size], xte::as_xvalue(args...[(i * mod % size + mod) % size]))
				), args...),
				xte::assign(args...[size - mod], xte::as_xvalue(tmp))
			))(xte::as_xvalue(args...[0]), args...),
			xte::unroll<mod>([]<xte::uz i>(auto&... args) XTE_RETURNS(
				([](auto tmp, auto&... args) XTE_RETURNS(
					xte::unroll<(size / mod)>([]<xte::uz j>(auto&... args) XTE_RETURNS(
						xte::assign(args...[i + j * mod], xte::as_xvalue(args...[(i + j * mod + mod) % size]))
					), args...),
					xte::assign(args...[size - mod + i], xte::as_xvalue(tmp))
				))(xte::as_xvalue(args...[i]), args...)
			), args...)
		))(args...)
	)
}

#endif

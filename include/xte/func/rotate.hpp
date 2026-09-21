#ifndef DETAIL_XTE_HEADER_FUNC_ROTATE
#	define DETAIL_XTE_HEADER_FUNC_ROTATE
#
#	include "../aliases.hpp"
#	include "../array.hpp"
#	include "../assign.hpp"
#	include "../func/repeat.hpp"
#	include "../math/gcd.hpp"
#	include "../preproc/returns.hpp"
#	include "../qual_cast.hpp"
#	include <meta>

namespace xte {
	template<xte::uz distance = 1, typename... arg_types,
		xte::uz gcd = xte::gcd(sizeof...(arg_types), distance)>
	constexpr auto rotate(arg_types&... args) XTE_RETURNS(
		xte::repeat<(gcd * (gcd < sizeof...(args)))>([]<xte::uz i>(arg_types&... args) XTE_RETURNS(
			[:std::meta::substitute(
				^^decltype([]<xte::uz... j>(arg_types...[0] tmp, arg_types&... args) static XTE_RETURNS(
					xte::repeat<(sizeof...(j) - 1)>([]<xte::uz k>(arg_types&... args) XTE_RETURNS(
						xte::assign(args...[j...[k]], xte::as_xvalue(args...[j...[k + 1]]))
					), args...),
					xte::assign(args...[j...[sizeof...(j) - 1]], xte::as_xvalue(tmp))
				))::operator(),
				([] {
					static constexpr xte::uz mod = distance % sizeof...(args);
					xte::array<std::meta::info> indices;
					for (xte::uz last = i; indices.size() < (sizeof...(args) / gcd);) {
						indices.append(std::meta::reflect_constant(last));
						xte::uz diff = sizeof...(args) - last;
						last = (diff < mod) ? (mod - diff) : (last + mod);
					}
					return indices;
				})()
			):](xte::as_xvalue(args...[i]), args...)
		), args...)
	)
}

#endif

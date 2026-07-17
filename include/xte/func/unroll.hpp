#ifndef DETAIL_XTE_HEADER_FUNC_UNROLL
#	define DETAIL_XTE_HEADER_FUNC_UNROLL
#
#	include "../func/unfold.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../util/number_types.hpp"

namespace xte {
	template<xte::uz n>
	constexpr auto unroll(auto&& func, auto&&... args) XTE_RETURNS(
		xte::unfold<n>([]<xte::uz... i>(auto&& func, auto&&... args) XTE_RETURNS(
			(..., void(func.template operator()<i>(args...)))
		), XTE_FWD(func), XTE_FWD(args)...)
	)
}

#endif

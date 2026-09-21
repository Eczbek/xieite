#ifndef DETAIL_XTE_HEADER_FUNC_REPEAT
#	define DETAIL_XTE_HEADER_FUNC_REPEAT
#
#	include "../aliases.hpp"
#	include "../func/unfold.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"

namespace xte {
	template<xte::uz count>
	constexpr auto repeat(auto&& func, auto&&... args) XTE_RETURNS(
		xte::unfold<count>([]<xte::uz... i>(auto&& func, auto&&... args) XTE_RETURNS(
			(..., void(func.template operator()<i>(args...)))
		), XTE_FWD(func), XTE_FWD(args)...)
	)
}

#endif

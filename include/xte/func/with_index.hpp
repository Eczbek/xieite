#ifndef DETAIL_XTE_HEADER_FUNC_WITH_INDEX
#	define DETAIL_XTE_HEADER_FUNC_WITH_INDEX
#
#	include "../func/unfold.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../util/number_types.hpp"

namespace xte {
	template<xte::uz size>
	[[nodiscard]] constexpr auto with_index(xte::uz index, auto&& func, auto&&... args) XTE_RETURNS(
		xte::unfold<size>([]<xte::uz... i>(xte::uz index, auto&& func, auto&&... args) XTE_RETURNS(
			(void)(... || ((i == index) && (void(XTE_FWD(func).template operator()<i>(XTE_FWD(args)...)), true)))
		), index, XTE_FWD(func), XTE_FWD(args)...)
	)
}

#endif

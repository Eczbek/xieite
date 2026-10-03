#ifndef DETAIL_XTE_HEADER_FUNC_UNFOLD
#	define DETAIL_XTE_HEADER_FUNC_UNFOLD
#
#	include "../aliases.hpp"
#	include "../macros.hpp"
#	include "../meta/seq.hpp"

namespace xte {
	template<xte::uz count>
	[[nodiscard]] constexpr auto unfold(auto&& func, auto&&... args) XTE_RETURNS(
		([]<xte::uz... i>(xte::seq<i...>, auto&& func, auto&&... args) XTE_RETURNS(
			XTE_FWD(func).template operator()<i...>(XTE_FWD(args)...)
		))(xte::make_seq<count>, XTE_FWD(func), XTE_FWD(args)...)
	)
}

#endif

#ifndef DETAIL_XTE_HEADER_FUNC_UNFOLD
#	define DETAIL_XTE_HEADER_FUNC_UNFOLD
#
#	include "../meta/make_seq.hpp"
#	include "../meta/seq.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<xte::uz n>
	[[nodiscard]] constexpr auto unfold(auto&& func, auto&&... args) XTE_ARROW(
		([]<xte::uz... i>(xte::seq<i...>, auto&& func, auto&&... args) XTE_ARROW(
			XTE_FWD(func).template operator()<i...>(XTE_FWD(args)...)
		))(xte::make_seq<n>, XTE_FWD(func), XTE_FWD(args)...)
	)
}

#endif

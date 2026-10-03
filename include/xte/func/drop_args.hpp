#ifndef DETAIL_XTE_HEADER_FUNC_DROP_ARGS
#	define DETAIL_XTE_HEADER_FUNC_DROP_ARGS
#
#	include "../macros.hpp"
#	include "../qual_traits.hpp"

namespace xte {
	[[nodiscard]] constexpr auto drop_args(auto&& func) XTE_RETURNS(
		[func = XTE_FWD(func)](this auto&& self, auto&&...) XTE_RETURNS(
			xte::like<decltype(self)>(func)()
		)
	)
}

#endif

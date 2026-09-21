#ifndef DETAIL_XTE_HEADER_FUNC_FOLD
#	define DETAIL_XTE_HEADER_FUNC_FOLD
#
#	include "../aliases.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"

namespace DETAIL_XTE::fold {
	template<xte::uz count, typename func_type, typename value_type>
	struct impl {
		func_type&& func;
		value_type value;

		[[nodiscard]] constexpr impl(func_type&& func, value_type&& value) XTE_CONSTRUCTS(
			(func,(XTE_FWD(func)))
			(value,(XTE_FWD(value)))
		)

		[[nodiscard]] constexpr auto operator->*(this auto&& self, auto&& next) XTE_RETURNS_CHOOSE(
			count,
			(DETAIL_XTE::fold::impl<(count - 1), func_type, decltype(self.func(XTE_FWD(self.value), XTE_FWD(next)))>(XTE_FWD(self.func), self.func(XTE_FWD(self.value), XTE_FWD(next)))),
			XTE_FWD(self.func)(XTE_FWD(self.value), XTE_FWD(next))
		)
	};
}

namespace xte {
	[[nodiscard]] constexpr auto fold(auto&& func, auto&& arg, auto&&... args) XTE_RETURNS(
		(DETAIL_XTE::fold::impl<(sizeof...(args) - 1), decltype(func), decltype(arg)>(XTE_FWD(func), XTE_FWD(arg))->*...->*XTE_FWD(args))
	)
}

#endif

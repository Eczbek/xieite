#ifndef DETAIL_XTE_HEADER_META_FOLD
#	define DETAIL_XTE_HEADER_META_FOLD
#
#	include "../func/unfold.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<auto func, decltype(auto) x>
	struct fold {
		static constexpr decltype(auto) value = x;

		template<xte::uz i>
		DETAIL_XTE::fold<func, func.template operator()<x, i>()> operator->*(xte::wrap_value<i>);
	};
}

namespace xte {
	template<auto func, decltype(auto) x, xte::uz n>
	constexpr decltype(auto) fold = xte::unfold<n>([]<xte::uz... i> -> decltype(auto) {
		return decltype((DETAIL_XTE::fold<func, x>()->*...->*xte::wrap_value<i>()))::value;
	});
}

#endif

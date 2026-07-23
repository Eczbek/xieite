#ifndef DETAIL_XTE_HEADER_META_FOLD
#	define DETAIL_XTE_HEADER_META_FOLD
#
#	include "../func/unfold.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../util/number_types.hpp"

namespace DETAIL_XTE::fold {
	template<decltype(auto) func, decltype(auto) x>
	struct impl {
		static constexpr decltype(auto) value = x;

		template<xte::uz i>
		impl<func, func.template operator()<x, i>()> operator->*(xte::wrap_value<i>);
	};
}

namespace xte {
	template<decltype(auto) func, decltype(auto) x, xte::uz count>
	constexpr decltype(auto) fold = xte::unfold<count>([]<xte::uz... i> -> decltype(auto) {
		return decltype((DETAIL_XTE::fold::impl<func, x>()->*...->*xte::wrap_value<i>()))::value;
	});
}

#endif

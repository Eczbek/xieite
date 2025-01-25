#pragma once

#include "../meta/t.hpp"

namespace XIEITE_DETAIL::fold {
	template<auto fn, typename T>
	struct impl {
		using type = T;

		template<typename U>
		XIEITE_DETAIL::fold::impl<fn, decltype(fn.template operator()<T, U>())> operator->*(xieite::t<U>) const;
	};
}

namespace xieite {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((XIEITE_DETAIL::fold::impl<fn, T>()->*...->*xieite::t<Ts>()))::type;
}

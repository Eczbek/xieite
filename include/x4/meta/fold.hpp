#pragma once

#include <type_traits>

namespace DETAIL_X4::fold {
	template<auto fn, typename T>
	struct impl {
		using type = T;

		template<typename U>
		DETAIL_X4::fold::impl<fn, decltype(fn.template operator()<T, U>())> operator->*(std::type_identity<U>) const;
	};
}

namespace x4 {
	template<auto fn, typename T, typename... Ts>
	using fold = decltype((DETAIL_X4::fold::impl<fn, T>()->*...->*std::type_identity<Ts>()))::type;
}

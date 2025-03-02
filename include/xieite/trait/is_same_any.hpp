#pragma once

#include <concepts>
#include <type_traits>

namespace DETAIL_XIEITE::is_same_any {
	template<typename...>
	struct impl : std::true_type {};

	template<typename T, typename... Ts>
	struct impl<T, Ts...> : std::bool_constant<(... || std::same_as<T, Ts>)> {};
}

namespace xieite {
	template<typename... Ts>
	concept is_same_any = DETAIL_XIEITE::is_same_any::impl<Ts...>::value;
}

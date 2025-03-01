#pragma once

#include <concepts>
#include <type_traits>

namespace DETAIL_X4::is_same_any {
	template<typename...>
	struct impl : std::true_type {};

	template<typename T, typename... Ts>
	struct impl<T, Ts...> : std::bool_constant<(... || std::same_as<T, Ts>)> {};
}

namespace x4 {
	template<typename... Ts>
	concept issameany = DETAIL_X4::is_same_any::impl<Ts...>::value;
}

#pragma once

#include <type_traits>
#include <utility>

namespace x4 {
	template<typename T, typename... Us>
	concept isnoexconv = (... && (
		std::is_nothrow_convertible_v<T, Us>
		&& requires { { static_cast<Us>(std::declval<T>()) } noexcept; }
	));
}

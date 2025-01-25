#pragma once

#include <type_traits>
#include <utility>

namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv = (... && (
		std::is_nothrow_convertible_v<T, Us>
		&& requires {
			{ static_cast<Us>(std::declval<T>()) } noexcept;
		}
	));
}

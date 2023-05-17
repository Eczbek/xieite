#pragma once

#include <concepts>
#include <type_traits>

namespace xieite::traits {
	template<typename, typename>
	inline constexpr bool isFunction = false;

	template<typename Result, typename... Parameters, std::invocable<Parameters...> Invocable>
	inline constexpr bool isFunction<Invocable, Result(Parameters...)> = std::convertible_to<std::invoke_result_t<Invocable, Parameters...>, Result>;
}

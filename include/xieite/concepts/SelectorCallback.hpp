#pragma once

#include <concepts>
#include <type_traits>

namespace xieite::concepts {
	template<typename Invocable, typename Argument>
	concept SelectorCallback = std::convertible_to<std::invoke_result_t<Invocable, Argument>, bool>;
}

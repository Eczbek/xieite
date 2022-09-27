#pragma once

#include <concepts>
#include <type_traits>


namespace gcufl::concepts {
	template<typename T, typename U>
	concept Comparator = std::convertible_to<std::invoke_result_t<T, const U&, const U&>, bool>;
}

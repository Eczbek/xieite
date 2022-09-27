#pragma once

#include <concepts>


namespace gcufl::concepts {
	template<typename T, typename U>
	concept Comparator = std::convertible_to<std::invoke_result<T(U, U)>, bool>;
}

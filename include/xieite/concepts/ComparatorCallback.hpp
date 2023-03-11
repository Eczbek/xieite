#pragma once
#include <concepts> // std::convertible_to
#include <type_traits> // std::invoke_result_t

namespace xieite::concepts {
	template<typename T, typename U>
	concept ComparatorCallback = std::convertible_to<std::invoke_result_t<T, U&&, U&&>, bool>;
}

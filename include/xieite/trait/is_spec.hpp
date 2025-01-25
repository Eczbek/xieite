#pragma once

#include <utility>

namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec = (... && requires { ([]<typename... Args>(const Ms<Args...>&) {})(std::declval<T>()); });
}

// TODO: Remove after `std::specialization_of` is implemented

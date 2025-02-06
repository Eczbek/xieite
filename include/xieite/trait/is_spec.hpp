#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec = (... && requires { ([]<typename... Args>(std::type_identity<Ms<Args...>>) {})(std::type_identity<T>()); });
}

// TODO: Remove after `std::specialization_of` is implemented

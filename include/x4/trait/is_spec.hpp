#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, template<typename...> typename... Ms>
	concept isspec = (... && requires { ([]<typename... Args>(std::type_identity<Ms<Args...>>) {})(std::type_identity<T>()); });
}

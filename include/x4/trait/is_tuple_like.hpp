#pragma once

#include <tuple>

namespace x4 {
	template<typename T>
	concept istuplike = requires { std::tuple_size<std::remove_cvref_t<T>>::value; };
}

#pragma once

#include <tuple>

namespace xieite {
	template<typename T>
	concept is_tuple_like = requires { std::tuple_size<std::remove_cvref_t<T>>::value; };
}

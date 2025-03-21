#pragma once

#include <type_traits>

namespace xieite {
	template<typename T, auto = [] {}>
	concept is_complete = requires { ([]<typename U, auto = sizeof(U)>(std::type_identity<U>) {})(std::type_identity<T>()); };
}

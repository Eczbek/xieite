#pragma once

#include <type_traits>

namespace x4 {
	template<typename T, auto = [] {}>
	concept iscomplete = requires { ([]<typename U, auto = sizeof(U)>(std::type_identity<U>) {})(std::type_identity<T>()); };
}

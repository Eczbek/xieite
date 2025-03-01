#pragma once

#include <chrono>
#include <type_traits>
#include "../trait/isarith.hpp"
#include "../trait/isratio.hpp"
#include "../trait/rmcv.hpp"

namespace x4 {
	template<typename T>
	concept isdur = requires { ([]<x4::isarith U, x4::isratio V>(std::type_identity<std::chrono::duration<U, V>>) {})(std::type_identity<x4::rmcv<T>>()); };
}

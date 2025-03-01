#pragma once

#include <type_traits>
#include "../trait/setcpctor.hpp"

namespace x4 {
	template<typename T>
	using cpcpctor = x4::setcpctor<std::is_copy_constructible_v<T>>;
}

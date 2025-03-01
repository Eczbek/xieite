#pragma once

#include <type_traits>
#include "../trait/setdfltctor.hpp"

namespace x4 {
	template<typename T>
	using cdfltctor = x4::setdfltctor<std::is_default_constructible_v<T>>;
}

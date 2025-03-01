#pragma once

#include <concepts>
#include <type_traits>

namespace x4 {
	template<typename T>
	concept isdecayed = std::same_as<T, std::decay_t<T>>;
}

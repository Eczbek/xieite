#pragma once

#include <concepts>
#include <type_traits>
#include "../trait/isarith.hpp"

namespace x4 {
	template<typename T>
	concept isnumeric = x4::isarith<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}

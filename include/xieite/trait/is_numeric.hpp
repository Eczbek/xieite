#pragma once

#include <concepts>
#include <type_traits>
#include "../trait/is_arith.hpp"

namespace xieite {
	template<typename T>
	concept is_numeric = xieite::is_arith<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}

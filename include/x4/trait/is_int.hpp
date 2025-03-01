#pragma once

#include <concepts>
#include <type_traits>

namespace x4 {
	template<typename T>
	concept isint = std::integral<T> && !std::same_as<std::remove_cv_t<T>, bool>;
}

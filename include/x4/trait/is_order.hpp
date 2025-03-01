#pragma once

#include <compare>
#include <type_traits>
#include "../trait/issame_any.hpp"

namespace x4 {
	template<typename T>
	concept isorder = x4::issame_any<std::remove_cv_t<T>, std::strong_ordering, std::weak_ordering, std::partial_ordering>;
}

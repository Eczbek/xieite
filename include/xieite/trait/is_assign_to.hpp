#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename U>
	concept is_assign_to = std::assignable_from<U, T>;
}

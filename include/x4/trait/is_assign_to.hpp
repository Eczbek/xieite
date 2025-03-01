#pragma once

#include <concepts>

namespace x4 {
	template<typename T, typename U>
	concept isassto = std::assignable_from<U, T>;
}

#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept ispolymorphic = std::is_polymorphic_v<T>;
}

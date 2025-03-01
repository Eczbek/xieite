#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isabstract = std::is_abstract_v<T>;
}

#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_union = std::is_union_v<T>;
}

#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_std_layout = std::is_standard_layout_v<T>;
}

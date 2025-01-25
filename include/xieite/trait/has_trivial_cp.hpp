#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_cp = std::is_trivially_copyable_v<T>;
}

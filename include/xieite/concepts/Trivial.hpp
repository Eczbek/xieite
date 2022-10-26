#pragma once
#include <type_traits>

namespace xieite::concepts {
	template<typename T>
	concept Trivial = std::is_trivial_v<T>;
}

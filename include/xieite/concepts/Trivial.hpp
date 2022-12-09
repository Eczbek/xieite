#pragma once
#include <type_traits> // std::is_trivial_v

namespace xieite::concepts {
	template<typename T>
	concept Trivial = std::is_trivial_v<T>;
}

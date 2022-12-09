#pragma once
#include <type_traits> // std::is_same_v

namespace xieite::concepts {
	template<typename T>
	concept Decayed = std::is_same_v<T, std::decay_t<T>>;
}

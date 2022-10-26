#pragma once
#include <type_traits>

namespace xieite::concepts {
	template<typename T>
	concept Enumerator = std::is_enum_v<T>;
}

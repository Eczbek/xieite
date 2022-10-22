#pragma once
#include <type_traits>

namespace gcufl::concepts {
	template<typename T>
	concept Enumerator = std::is_enum_v<T>;
}

#pragma once
#include <type_traits>

namespace gcufl::concepts {
	template<typename T>
	concept Enum = std::is_enum_v<T>;
}

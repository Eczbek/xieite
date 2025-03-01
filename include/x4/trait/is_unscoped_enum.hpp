#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isunscopenum = std::is_enum_v<T> && !std::is_scoped_enum_v<T>;
}

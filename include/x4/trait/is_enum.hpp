#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isenum = std::is_enum_v<T>;
}

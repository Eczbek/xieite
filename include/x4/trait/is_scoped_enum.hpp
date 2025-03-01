#pragma once

#include <type_traits>

namespace x4 {
	template<typename T>
	concept isscopenum = std::is_scoped_enum_v<T>;
}

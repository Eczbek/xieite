#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_enum = std::is_enum_v<T>;
}

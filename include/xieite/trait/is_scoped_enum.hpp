#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_scoped_enum = std::is_scoped_enum_v<T>;
}

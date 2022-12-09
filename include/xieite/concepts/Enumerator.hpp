#pragma once
#include <type_traits> // std::is_enum_v

namespace xieite::concepts {
	template<typename T>
	concept Enumerator = std::is_enum_v<T>;
}

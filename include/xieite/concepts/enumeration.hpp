#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Enumeration = std::is_enum_v<Type>;
}

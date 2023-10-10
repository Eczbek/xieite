#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Trivial = std::is_trivial_v<Type>;
}

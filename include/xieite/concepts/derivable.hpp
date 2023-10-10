#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Derivable = std::is_class_v<Type> && !std::is_final_v<Type>;
}

#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept CopyAssignable = std::is_copy_assignable_v<Type>;
}

#pragma once

#include <concepts>

namespace xieite::concepts {
	template<typename Type>
	concept Integer = std::integral<Type> && !std::same_as<Type, bool>;
}

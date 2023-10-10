#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Aggregate = std::is_aggregate_v<Type>;
}

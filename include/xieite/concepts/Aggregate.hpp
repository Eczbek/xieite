#pragma once
#include <type_traits>

namespace xieite::concepts {
	template<typename T>
	concept Aggregate = std::is_aggregate_v<T>;
}

#pragma once
#include <type_traits> // std::is_aggregate_v

namespace xieite::concepts {
	template<typename T>
	concept Aggregate = std::is_aggregate_v<T>;
}

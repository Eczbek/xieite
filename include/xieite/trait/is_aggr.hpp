#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_aggr = std::is_aggregate_v<T>;
}

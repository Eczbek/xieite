#pragma once

#include <type_traits>


namespace gcufl::concepts {
	template<typename T>
	concept Aggregate = std::is_aggregate_v<T>;
}

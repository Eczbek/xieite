#pragma once

#include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Aggregate = std::is_aggregate_v<Any>;
}

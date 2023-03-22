#pragma once

#include <cstddef>
#include <functional>

namespace xieite::concepts {
	template<typename Any>
	concept Hashable = requires(Any value) {
		{ std::hash<Any>()(value) } -> std::convertible_to<std::size_t>;
	};
}

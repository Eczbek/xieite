#pragma once
#include <cstddef> // std::size_t
#include <functional> // std::hash

namespace xieite::concepts {
	template<typename Any>
	concept Hashable = requires(Any value) {
		{ std::hash<Any>()(value) } -> std::convertible_to<std::size_t>;
	};
}

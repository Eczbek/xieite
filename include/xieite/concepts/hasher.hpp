#pragma once

#include <concepts>
#include <cstddef>
#include <functional>

namespace xieite::concepts {
	template<typename Type, typename Argument>
	concept Hasher = requires(Type hasher, Argument value) {
		{ std::invoke(hasher, value) } -> std::convertible_to<std::size_t>;
	};
}

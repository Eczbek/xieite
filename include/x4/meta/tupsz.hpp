#pragma once

#include <cstddef>
#include <tuple>
#include <type_traits>

namespace x4 {
	template<typename T>
	constexpr std::size_t tupsz = std::tuple_size_v<std::remove_cvref_t<T>>;
}

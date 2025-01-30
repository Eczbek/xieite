#pragma once

#include <cstddef>
#include <tuple>
#include <type_traits>

namespace xieite {
	template<typename T>
	constexpr std::size_t tuple_size = std::tuple_size_v<std::remove_cvref_t<T>>;
}

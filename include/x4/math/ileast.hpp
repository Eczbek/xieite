#pragma once

#include <cstddef>
#include <type_traits>
#include "../math/uleast.hpp"

namespace x4 {
	template<std::size_t bits>
	using ileast = std::make_signed_t<x4::uleast<bits>>;
}

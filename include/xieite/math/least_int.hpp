#pragma once

#include <cstddef>
#include <type_traits>
#include "../math/least_uint.hpp"

namespace xieite {
	template<std::size_t bits>
	using least_int = std::make_signed_t<xieite::least_uint<bits>>;
}

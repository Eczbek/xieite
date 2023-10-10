#pragma once

#include <cstddef>
#include "../system/byte_bits.hpp"

namespace xieite::types {
	template<typename Type>
	inline constexpr std::size_t sizeBits = sizeof(Type) * xieite::system::byteBits;
}

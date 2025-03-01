#pragma once

#include <bit>
#include <cstddef>
#include <memory>
#include "../pp/restrict.hpp"

namespace x4 {
	template<std::size_t align = 1, typename T>
	requires(std::has_single_bit(align))
	void amemcp(T* X4RESTRICT dest, const T* X4RESTRICT src, std::size_t size) noexcept {
		[[assume(!(size % align))]];
		auto aligned_dest = reinterpret_cast<char* X4RESTRICT>(std::assume_aligned<align>(dest));
		auto aligned_src = reinterpret_cast<const char* X4RESTRICT>(std::assume_aligned<align>(src));
		for (std::size_t i = 0; i < size; ++i) {
			aligned_dest[i] = aligned_src[i];
		}
	}
}

#pragma once

#include <bit>
#include <cstddef>
#include <memory>

namespace xieite {
	template<std::size_t align = 1, typename T>
	requires(std::has_single_bit(align))
	void aligned_bzero(T* src, std::size_t size) noexcept {
		[[assume(!(size % align))]];
		auto aligned_src = reinterpret_cast<char*>(std::assume_aligned<align>(src));
		for (std::size_t i = 0; i < size; ++i) {
			aligned_src[i] = '\0';
		}
	}
}

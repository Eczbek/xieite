#ifndef DETAIL_XIEITE_HEADER_SYS_ALIGNED_MEMSET
#	define DETAIL_XIEITE_HEADER_SYS_ALIGNED_MEMSET
#
#	include <bit>
#	include <cstddef>
#	include <memory>

namespace xieite {
	template<std::size_t align = 1, typename T>
	requires(std::has_single_bit(align))
	void aligned_memset(T* src, unsigned char x, std::size_t size) noexcept {
		[[assume(!(size % align))]];
		auto aligned_src = reinterpret_cast<unsigned char*>(std::assume_aligned<align>(src));
		for (std::size_t i = 0; i < size; ++i) {
			aligned_src[i] = x;
		}
	}
}

#endif

// Compile with `-fno-builtin-memset` lest the function be optimized out

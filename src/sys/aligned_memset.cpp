export module xieite:aligned_memset;

import std;

export namespace xieite {
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

// NOTE: Compile with `-fno-builtin-memset` lest the function be recognized and eliminated

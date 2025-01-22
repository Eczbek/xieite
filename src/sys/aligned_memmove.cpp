export module xieite:aligned_memmove;

import std;

export namespace xieite {
	template<std::size_t align = 1, typename T>
	requires(std::has_single_bit(align))
	void aligned_memmove(T* dest, const T* src, std::size_t size) noexcept {
		[[assume(!(size % align))]];
		auto aligned_dest = reinterpret_cast<char*>(std::assume_aligned<align>(dest));
		auto aligned_src = reinterpret_cast<const char*>(std::assume_aligned<align>(src));
		for (std::size_t i = 0; i < size; ++i) {
			aligned_dest[i] = aligned_src[i];
		}
	}
}

// NOTE: Compile with `-fno-builtin-memmove` lest the function be recognized and eliminated

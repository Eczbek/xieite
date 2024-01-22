#ifndef XIEITE_HEADER_HASHES_XOR_SHIFT
#	define XIEITE_HEADER_HASHES_XOR_SHIFT

#	include <concepts>
#	include <cstddef>

namespace xieite::hashes {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer xorShift(const Integer value, const std::size_t bits) noexcept {
		return value ^ (value >> bits);
	}
}

#endif

#ifndef XIEITE_HEADER_HASHES_DISTRIBUTE
#	define XIEITE_HEADER_HASHES_DISTRIBUTE

#	include <concepts>
#	include <limits>
#	include <numbers>
#	include "../bits/xor_shift.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::hashes {
	template<std::integral Integer, std::floating_point Phi = double>
	[[nodiscard]] constexpr Integer distribute(const Integer value) noexcept {
		return static_cast<Integer>(std::numeric_limits<xieite::types::MaybeUnsigned<Integer>>::max() / std::numbers::phi_v<Phi>) * xieite::bits::xorShift(std::numeric_limits<xieite::types::MaybeUnsigned<Integer>>::max() / 3 * xieite::bits::xorShift(value, sizeof(Integer) * 4), sizeof(Integer) * 4);
	}
}

#endif

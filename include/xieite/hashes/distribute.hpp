#ifndef XIEITE_HEADER_HASHES_DISTRIBUTE
#	define XIEITE_HEADER_HASHES_DISTRIBUTE

#	include <concepts>
#	include <limits>
#	include <numbers>
#	include "../bits/xor_shift.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::hashes {
	template<std::integral Integral_, std::floating_point Phi_ = double>
	[[nodiscard]] constexpr Integral_ distribute(const Integral_ value) noexcept {
		return static_cast<Integral_>(std::numeric_limits<xieite::types::TryUnsigned<Integral_>>::max() / std::numbers::phi_v<Phi_>) * xieite::bits::xorShift(std::numeric_limits<xieite::types::TryUnsigned<Integral_>>::max() / 3 * xieite::bits::xorShift(value, sizeof(Integral_) * 4), sizeof(Integral_) * 4);
	}
}

#endif

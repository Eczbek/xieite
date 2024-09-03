export module xieite:hashes.distribute;

import std;
import :bits.xorShift;
import :types.TryUnsigned;

export namespace xieite::hashes {
	template<std::integral Integral, std::floating_point Phi = double>
	[[nodiscard]] constexpr Integral distribute(const Integral value) noexcept {
		return static_cast<Integral>(std::numeric_limits<xieite::types::TryUnsigned<Integral>>::max() / std::numbers::phi_v<Phi>) * xieite::bits::xorShift(std::numeric_limits<xieite::types::TryUnsigned<Integral>>::max() / 3 * xieite::bits::xorShift(value, sizeof(Integral) * 4), sizeof(Integral) * 4);
	}
}

export module xieite:hash_dist;

import std;
import :try_unsign;
import :xor_shift;

export namespace xieite {
	template<std::integral T, std::floating_point Phi = double>
	[[nodiscard]] constexpr T hash_dist(T n) noexcept {
		return static_cast<T>(std::numeric_limits<xieite::try_unsign<T>>::max() / std::numbers::phi_v<Phi>) * xieite::xor_shift(std::numeric_limits<xieite::try_unsign<T>>::max() / 3 * xieite::xor_shift(n, sizeof(T) * 4), sizeof(T) * 4);
	}
}

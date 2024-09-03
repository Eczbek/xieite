export module xieite:math.signCast;

import std;
import :types.TrySigned;
import :types.TryUnsigned;

export namespace xieite::math {
	template<std::integral Target, std::integral Source>
	[[nodiscard]] constexpr Target signCast(const Source value) noexcept {
		return static_cast<Target>(static_cast<std::conditional_t<std::signed_integral<Target>, xieite::types::TrySigned<Source>, xieite::types::TryUnsigned<Source>>>(value));
	}
}

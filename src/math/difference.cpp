export module xieite:math.difference;

import :concepts.Arithmetic;
import :types.TryUnsigned;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr xieite::types::TryUnsigned<Arithmetic> difference(const Arithmetic value1, const Arithmetic value2) noexcept {
		return (value1 > value2) ? (static_cast<xieite::types::TryUnsigned<Arithmetic>>(value1) - static_cast<xieite::types::TryUnsigned<Arithmetic>>(value2)) : (static_cast<xieite::types::TryUnsigned<Arithmetic>>(value2) - static_cast<xieite::types::TryUnsigned<Arithmetic>>(value1));
	}
}

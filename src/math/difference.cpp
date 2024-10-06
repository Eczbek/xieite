export module xieite:math.difference;

import std;
import :concepts.Arithmetic;
import :types.TryUnsigned;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr xieite::types::TryUnsigned<Arithmetic> difference(const Arithmetic value1, const std::type_identity_t<Arithmetic> value2) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			return std::abs(value1 - value2);
		} else {
			using Result = xieite::types::TryUnsigned<Arithmetic>;
			return (value1 > value2)
				? (static_cast<Result>(value1) - static_cast<Result>(value2))
				: (static_cast<Result>(value2) - static_cast<Result>(value1));
		}
	}
}

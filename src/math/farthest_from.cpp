export module xieite:math.farthestFrom;

import std;
import :concepts.Arithmetic;
import :math.difference;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic& farthestFrom(const Arithmetic target, std::type_identity_t<Arithmetic>& value1, std::type_identity_t<Arithmetic>& value2) noexcept {
		return (xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value2 : value1;
	}

	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic farthestFrom(const Arithmetic target, const std::type_identity_t<Arithmetic>& value1, const std::type_identity_t<Arithmetic>& value2) noexcept {
		return xieite::math::farthestFrom(target, static_cast<Arithmetic>(value1), static_cast<Arithmetic>(value2));
	}
}

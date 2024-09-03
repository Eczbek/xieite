export module xieite:math.almostEqual;

import std;
import :concepts.Arithmetic;
import :math.absolute;
import :math.difference;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool almostEqual(const Arithmetic value1, const Arithmetic value2) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			const Arithmetic scale = std::abs(value1) + std::abs(value2);
			return std::abs(value1 - value2) <= (std::numeric_limits<Arithmetic>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		} else {
			return value1 == value2;
		}
	}

	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool almostEqual(const Arithmetic value1, const Arithmetic value2, const Arithmetic epsilon) noexcept {
		if constexpr (std::floating_point<Arithmetic>) {
			return std::abs(value1 - value2) <= std::abs(epsilon);
		} else {
			return xieite::math::difference(value1, value2) <= xieite::math::absolute(epsilon);
		}
	}
}

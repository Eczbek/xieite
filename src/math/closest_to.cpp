export module xieite:math.closestTo;

import std;
import :concepts.Arithmetic;
import :math.difference;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic& closestTo(const Arithmetic target, std::common_type_t<Arithmetic>& value1, std::common_type_t<Arithmetic>& value2) noexcept {
		return (xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value2 : value1;
	}

	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic closestTo(const Arithmetic target, const std::common_type_t<Arithmetic>& value1, const std::common_type_t<Arithmetic>& value2) noexcept {
		return xieite::math::closestTo(target, static_cast<Arithmetic>(value1), static_cast<Arithmetic>(value2));
	}
}

export module xieite:math.wrap;

import std;
import :concepts.Arithmetic;
import :math.modulo;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic wrap(const Arithmetic value, const std::common_type_t<Arithmetic> limit1, const std::common_type_t<Arithmetic> limit2) noexcept {
		const Arithmetic minimum = std::min(limit1, limit2);
		return xieite::math::modulo(value - minimum, std::max(limit1, limit2) - minimum + 1) + minimum;
	}
}

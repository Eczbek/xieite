export module xieite:tan;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T, xieite::is_arith U = std::common_type_t<T, double>>
	[[nodiscard]] constexpr U tan(T theta, bool inverse, bool hyperbolic, bool reciprocal) noexcept {
		switch ((0b001 * inverse) | (0b010 * hyperbolic) | (0b100 * reciprocal)) {
		case 0b000:
			return std::tan(static_cast<U>(theta));
		case 0b001:
			return std::atan(static_cast<U>(theta));
		case 0b010:
			return std::tanh(static_cast<U>(theta));
		case 0b011:
			return std::atanh(static_cast<U>(theta));
		case 0b100:
			return 1.0 / std::tan(static_cast<U>(theta));
		case 0b101:
			return 1.0 / std::atan(static_cast<U>(theta));
		case 0b110:
			return 1.0 / std::tanh(static_cast<U>(theta));
		case 0b111:
			return 1.0 / std::atanh(static_cast<U>(theta));
		}
		std::unreachable();
	}
}

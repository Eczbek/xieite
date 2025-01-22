export module xieite:cos;

import std;
import :is_arith;

export namespace xieite {
	template<xieite::is_arith T, xieite::is_arith U = std::common_type_t<T, double>>
	[[nodiscard]] constexpr U cos(T theta, bool inverse = false, bool hyperbolic = false, bool reciprocal = false) noexcept {
		switch ((0b001 * inverse) | (0b010 * hyperbolic) | (0b100 * reciprocal)) {
		case 0b000:
			return std::cos(static_cast<U>(theta));
		case 0b001:
			return std::acos(static_cast<U>(theta));
		case 0b010:
			return std::cosh(static_cast<U>(theta));
		case 0b011:
			return std::acosh(static_cast<U>(theta));
		case 0b100:
			return 1.0 / std::cos(static_cast<U>(theta));
		case 0b101:
			return 1.0 / std::acos(static_cast<U>(theta));
		case 0b110:
			return 1.0 / std::cosh(static_cast<U>(theta));
		case 0b111:
			return 1.0 / std::acosh(static_cast<U>(theta));
		}
		std::unreachable();
	}
}

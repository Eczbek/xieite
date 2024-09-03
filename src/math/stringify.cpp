export module xieite:math.stringify;

import std;
import :concepts.Arithmetic;
import :math.absolute;
import :math.almostEqual;
import :math.isNegative;
import :math.remainder;
import :math.SignedSize;
import :strings.NumberComponents;
import :types.TryUnsigned;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr std::string stringify(Arithmetic value, const std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		using Radix = std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic>;
		std::string result;
		if (!radix || xieite::math::almostEqual<Arithmetic>(value, 0)) {
			result += components.digits[0];
			if constexpr (std::floating_point<Arithmetic>) {
				result += components.points[0];
				result += components.digits[0];
			}
			return result;
		}
		const bool negative = xieite::math::isNegative(value);
		const xieite::types::TryUnsigned<Arithmetic> absoluteValue = xieite::math::absolute(value);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(absoluteValue), components.digits[1]);
		} else if (!std::unsigned_integral<Arithmetic> && (radix == static_cast<Radix>(-1))) {
			result = components.digits[1];
			std::size_t length = static_cast<std::size_t>(absoluteValue);
			while (--length) {
				result += components.digits[0];
				result += components.digits[1];
			}
		} else {
			[[maybe_unused]] std::size_t point = 0;
			const auto nextDigit = [&value, radix, components, &result](Radix index) -> void {
				value = static_cast<Arithmetic>(value / static_cast<Arithmetic>(radix));
				if (xieite::math::isNegative(index)) {
					index = xieite::math::isNegative(radix) ? (index - radix) : (index + radix);
					++value;
				}
				result.insert(0, 1, components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < components.digits.size())]);
			};
			if constexpr (std::floating_point<Arithmetic>) {
				value = std::abs(value);
				do {
					value *= static_cast<Arithmetic>(radix);
					++point;
				} while ((components.precision - point) && !xieite::math::almostEqual<Arithmetic>(std::fmod(value, 1), 0));
				value = std::round(value);
			} else {
				if (value == std::numeric_limits<Arithmetic>::min()) {
					nextDigit(-static_cast<Arithmetic>(value % radix));
				}
				value = static_cast<Arithmetic>(xieite::math::absolute(value));
			}
			while ((value >= 1) || (!std::unsigned_integral<Arithmetic> && (value <= static_cast<Arithmetic>(-1)))) {
				nextDigit(static_cast<Radix>(xieite::math::remainder(value, static_cast<Arithmetic>(radix))));
			}
			if constexpr (std::floating_point<Arithmetic>) {
				if (point >= result.size()) {
					result.insert(0, point - result.size() + 1, components.digits[0]);
				}
				result.insert(result.size() - point, 1, components.points[0]);
			}
		}
		if (negative) {
			result.insert(0, 1, components.negatives[0]);
		}
		return result;
	}
}

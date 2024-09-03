export module xieite:math.parse;

import std;
import :concepts.Arithmetic;
import :math.SignedSize;
import :math.splitBoolean;
import :strings.NumberComponents;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic parse(const std::string_view value, const std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		if (!radix) {
			return 0;
		}
		const bool negative = components.negatives.contains(value[0]);
		const std::size_t valueSize = value.size();
		if constexpr (std::floating_point<Arithmetic>) {
			Arithmetic integral = 0;
			Arithmetic fractional = 0;
			std::size_t point = 0;
			int power = 0;
			for (std::size_t i = negative || components.positives.contains(value[0]); i < valueSize; ++i) {
				const std::size_t index = components.digits.find(value[i]);
				if (index == std::string_view::npos) {
					if (components.points.contains(value[i])) {
						if (point) {
							break;
						}
						point = 1;
					} else if (components.exponents.contains(value[i])) {
						power = xieite::math::parse<int>(value.substr(i + 1), radix, components);
						break;
					}
					continue;
				}
				Arithmetic& part = (point ? fractional : integral);
				part = part * static_cast<Arithmetic>(radix) + static_cast<Arithmetic>(index);
				point += !!point;
			}
			return xieite::math::splitBoolean(!negative) * (integral + fractional / std::pow(radix, point - 1)) * std::pow(radix, power);
		} else {
			Arithmetic result = 0;
			for (std::size_t i = negative || components.positives.contains(value[0]); i < valueSize; ++i) {
				const std::size_t index = components.digits.find(value[i]);
				if (index == std::string_view::npos) {
					break;
				}
				result = static_cast<Arithmetic>(result * static_cast<Arithmetic>(radix) + static_cast<Arithmetic>(index));
			}
			return negative ? -result : result;
		}
	}
}

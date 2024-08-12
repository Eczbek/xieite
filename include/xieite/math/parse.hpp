#ifndef XIEITE_HEADER_MATH_PARSE
#	define XIEITE_HEADER_MATH_PARSE

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../strings/number_components.hpp"
#	include "../math/signed_size.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ parse(const std::string_view value, const std::conditional_t<std::floating_point<Arithmetic_>, xieite::math::SignedSize, Arithmetic_> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		if (!radix) {
			return 0;
		}
		const bool negative = components.negatives.contains(value[0]);
		const std::size_t valueSize = value.size();
		if constexpr (std::floating_point<Arithmetic_>) {
			Arithmetic_ integral = 0;
			Arithmetic_ fractional = 0;
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
				Arithmetic_& part = (point ? fractional : integral);
				part = part * static_cast<Arithmetic_>(radix) + static_cast<Arithmetic_>(index);
				point += !!point;
			}
			return xieite::math::splitBoolean(!negative) * (integral + fractional / std::pow(radix, point - 1)) * std::pow(radix, power);
		} else {
			Arithmetic_ result = 0;
			for (std::size_t i = negative || components.positives.contains(value[0]); i < valueSize; ++i) {
				const std::size_t index = components.digits.find(value[i]);
				if (index == std::string_view::npos) {
					break;
				}
				result = static_cast<Arithmetic_>(result * static_cast<Arithmetic_>(radix) + static_cast<Arithmetic_>(index));
			}
			return negative ? -result : result;
		}
	}
}

#endif

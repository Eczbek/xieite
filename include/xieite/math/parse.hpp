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

namespace xieite::detail {
	template<typename Result_, typename Radix_>
	[[nodiscard]] constexpr Result_ parseNumber(const std::string_view value, const Radix_ radix, const xieite::strings::NumberComponents components) noexcept {
		if (!radix) {
			return 0;
		}
		const bool negative = components.negatives.contains(value[0]);
		const std::size_t valueSize = value.size();
		if constexpr (std::floating_point<Result_>) {
			Result_ integral = 0;
			Result_ fractional = 0;
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
						power = xieite::detail::parseNumber<int>(value.substr(i + 1), radix, components);
						break;
					}
					continue;
				}
				Result_& part = (point ? fractional : integral);
				part = part * static_cast<Result_>(radix) + static_cast<Result_>(index);
				point += !!point;
			}
			return xieite::math::splitBoolean(!negative) * (integral + fractional / std::pow(radix, point - 1)) * std::pow(radix, power);
		} else {
			Result_ result = 0;
			for (std::size_t i = negative || components.positives.contains(value[0]); i < valueSize; ++i) {
				const std::size_t index = components.digits.find(value[i]);
				if (index == std::string_view::npos) {
					break;
				}
				result = static_cast<Result_>(result * static_cast<Result_>(radix) + static_cast<Result_>(index));
			}
			return negative ? -result : result;
		}
	}
}

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ parse(const std::string_view value, const std::conditional_t<std::floating_point<Arithmetic_>, xieite::math::SignedSize, Arithmetic_> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		return xieite::detail::parseNumber<Arithmetic_>(value, radix, components);
	}
}

#endif

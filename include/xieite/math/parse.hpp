#ifndef XIEITE_HEADER_MATH_PARSE
#	define XIEITE_HEADER_MATH_PARSE

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/specialization_of.hpp"
#	include "../strings/integer_components.hpp"
#	include "../math/signed_size.hpp"
#	include "../math/split_boolean.hpp"
#	include "../strings/to_lowercase.hpp"

namespace xieite::math {
	template<std::unsigned_integral>
	struct BigInteger;

	template<typename Number>
	requires(xieite::concepts::Arithmetic<Number> || xieite::concepts::SpecializationOf<Number, xieite::math::BigInteger>)
	[[nodiscard]] constexpr Number parse(const std::string_view value, const std::conditional_t<std::floating_point<Number>, xieite::math::SignedSize, Number> radix = 10, const xieite::strings::IntegerComponents& components = xieite::strings::IntegerComponents()) noexcept {
		if (!radix) {
			return 0;
		}
		const bool negative = value[0] == components.negative;
		const std::size_t valueSize = value.size();
		if constexpr (std::floating_point<Number>) {
			Number integral = 0;
			Number fractional = 0;
			std::size_t point = 0;
			xieite::math::SignedSize power = 0;
			for (std::size_t i = negative || (value[0] == components.positive); i < valueSize; ++i) {
				const std::size_t index = components.digits.find(value[i]);
				if (index == std::string_view::npos) {
					if (value[i] == components.point) {
						if (point) {
							break;
						}
						point = 1;
					} else if (xieite::strings::lowercase(value[i]) == xieite::strings::lowercase(components.exponent)) {
						power = xieite::math::parse<xieite::math::SignedSize>(value.substr(i + 1));
						break;
					}
				}
				Number& part = (point ? fractional : integral);
				part = part * static_cast<Number>(radix) + static_cast<Number>(index);
				point += !!point;
			}
			return xieite::math::splitBoolean(!negative) * (integral + fractional / std::pow(radix, point - 1)) * std::pow(radix, power);
		} else {
			Number result = 0;
			xieite::math::SignedSize power = 0;
			for (std::size_t i = negative || (value[0] == components.positive); i < valueSize; ++i) {
				const std::size_t index = components.digits.find(value[i]);
				if (index == std::string_view::npos) {
					break;
				}
				result = result * radix + static_cast<Number>(index);
			}
			return negative ? -result : result;
		}
	}
}

#endif

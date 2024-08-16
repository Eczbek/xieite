#ifndef XIEITE_HEADER_STRINGS_IS_NUMBER
#	define XIEITE_HEADER_STRINGS_IS_NUMBER

#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"
#	include "../math/signed_size.hpp"
#	include "../strings/number_components.hpp"

namespace xieite::strings {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool isNumber(const std::string_view value, const std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		std::size_t i = components.positives.contains(value[0]) || components.negatives.contains(value[0]);
		const std::size_t valueSize = value.size();
		const std::string_view digits = components.digits.substr(0, xieite::math::absolute(radix));
		if constexpr (std::floating_point<Arithmetic>) {
			bool point = false;
			for (; i < valueSize; ++i) {
				if (digits.contains(value[i])) {
					continue;
				}
				if (!point && components.points.contains(value[i])) {
					point = true;
					continue;
				}
				if ((i < (valueSize - 1)) && components.exponents.contains(value[i])) {
					return xieite::strings::isNumber<int>(value.substr(i + 1));
				}
				return false;
			}
		} else {
			for (; i < valueSize; ++i) {
				if (!digits.contains(value[i])) {
					return false;
				}
			}
		}
		return true;
	}
}

#endif

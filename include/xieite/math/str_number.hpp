#ifndef DETAIL_XIEITE_HEADER_MATH_STR_NUMBER
#	define DETAIL_XIEITE_HEADER_MATH_STR_NUMBER
#
#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <string>
#	include <type_traits>
#	include "../data/number_str_config.hpp"
#	include "../data/pad_front.hpp"
#	include "../math/abs.hpp"
#	include "../math/almost_equal.hpp"
#	include "../math/neg.hpp"
#	include "../math/rem.hpp"
#	include "../math/ssize_t.hpp"
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr std::string str_number(Arith x, std::conditional_t<std::floating_point<Arith>, xieite::ssize_t, Arith> radix = 10, const xieite::number_str_config& config = {}, std::size_t pad = 0) noexcept {
		using Radix = std::conditional_t<std::floating_point<Arith>, xieite::ssize_t, Arith>;
		std::string result;
		if (!radix || xieite::almost_equal(x, static_cast<Arith>(0))) {
			result += config.digits[0];
			if constexpr (std::floating_point<Arith>) {
				result += config.point[0];
				result += config.digits[0];
			}
			return result;
		}
		const bool neg = xieite::neg(x);
		const xieite::try_unsigned<Arith> abs = xieite::abs(x);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(abs), config.digits[1]);
		} else if (!std::unsigned_integral<Arith> && (radix == static_cast<Radix>(-1))) {
			result = config.digits[1];
			std::size_t length = static_cast<std::size_t>(abs);
			while (--length) {
				result += config.digits[0];
				result += config.digits[1];
			}
		} else {
			[[maybe_unused]] std::size_t point = 0;
			const auto next = [&x, radix, config, &result](Radix idx) -> void {
				x = static_cast<Arith>(x / static_cast<Arith>(radix));
				if (xieite::neg(idx)) {
					idx = xieite::neg(radix) ? (idx - radix) : (idx + radix);
					++x;
				}
				result.insert(0, 1, config.digits[static_cast<std::size_t>(idx) * (static_cast<std::size_t>(idx) < config.digits.size())]);
			};
			if constexpr (std::floating_point<Arith>) {
				x = std::abs(x);
				do {
					x *= static_cast<Arith>(radix);
					++point;
				} while ((config.precision - point) && !xieite::almost_equal(std::fmod(x, 1), static_cast<Arith>(0)));
				x = std::round(x);
			} else {
				if (x == std::numeric_limits<Arith>::min()) {
					next(static_cast<Radix>(-(x % static_cast<Arith>(radix))));
				}
				x = static_cast<Arith>(xieite::abs(x));
			}
			while ((x >= 1) || (!std::unsigned_integral<Arith> && (x <= static_cast<Arith>(-1)))) {
				next(static_cast<Radix>(xieite::rem(x, static_cast<Arith>(radix))));
			}
			if constexpr (std::floating_point<Arith>) {
				if (point >= result.size()) {
					result.insert(0, point - result.size() + 1, config.digits[0]);
				}
				result.insert(result.size() - point, 1, config.point[0]);
			}
		}
		if (neg) {
			result.insert(0, 1, config.minus[0]);
		}
		return xieite::pad_front(result, pad, config.digits[0]);
	}
}

#endif

#pragma once

#include <cmath>
#include <concepts>
#include <cstddef>
#include <string>
#include <type_traits>
#include "../ctnr/num_str_config.hpp"
#include "../ctnr/pad_front.hpp"
#include "../math/abs.hpp"
#include "../math/almost_eq.hpp"
#include "../math/neg.hpp"
#include "../math/rem.hpp"
#include "../math/ssize_t.hpp"
#include "../meta/try_unsign.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr std::string str_num(T n, std::conditional_t<std::floating_point<T>, xieite::ssize_t, T> radix = 10, xieite::num_str_config config = {}, std::size_t pad = 0) noexcept {
		using Radix = std::conditional_t<std::floating_point<T>, xieite::ssize_t, T>;
		std::string result;
		if (!radix || xieite::almost_eq(n, static_cast<T>(0))) {
			result += config.digit[0];
			if constexpr (std::floating_point<T>) {
				result += config.pt[0];
				result += config.digit[0];
			}
			return result;
		}
		const bool neg = xieite::neg(n);
		const xieite::try_unsign<T> abs = xieite::abs(n);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(abs), config.digit[1]);
		} else if (!std::unsigned_integral<T> && (radix == static_cast<Radix>(-1))) {
			result = config.digit[1];
			std::size_t length = static_cast<std::size_t>(abs);
			while (--length) {
				result += config.digit[0];
				result += config.digit[1];
			}
		} else {
			[[maybe_unused]] std::size_t point = 0;
			const auto next = [&n, radix, config, &result](Radix idx) -> void {
				n = static_cast<T>(n / static_cast<T>(radix));
				if (xieite::neg(idx)) {
					idx = xieite::neg(radix) ? (idx - radix) : (idx + radix);
					++n;
				}
				result.insert(0, 1, config.digit[static_cast<std::size_t>(idx) * (static_cast<std::size_t>(idx) < config.digit.size())]);
			};
			if constexpr (std::floating_point<T>) {
				n = std::abs(n);
				do {
					n *= static_cast<T>(radix);
					++point;
				} while ((config.prec - point) && !xieite::almost_eq(std::fmod(n, 1), static_cast<T>(0)));
				n = std::round(n);
			} else {
				if (n == std::numeric_limits<T>::min()) {
					next(-static_cast<T>(n % radix));
				}
				n = static_cast<T>(xieite::abs(n));
			}
			while ((n >= 1) || (!std::unsigned_integral<T> && (n <= static_cast<T>(-1)))) {
				next(static_cast<Radix>(xieite::rem(n, static_cast<T>(radix))));
			}
			if constexpr (std::floating_point<T>) {
				if (point >= result.size()) {
					result.insert(0, point - result.size() + 1, config.digit[0]);
				}
				result.insert(result.size() - point, 1, config.pt[0]);
			}
		}
		if (neg) {
			result.insert(0, 1, config.minus[0]);
		}
		return xieite::pad_front(result, pad, config.digit[0]);
	}
}

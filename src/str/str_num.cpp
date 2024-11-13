export module xieite:num_str;

import std;
import :abs;
import :almost_eq;
import :end;
import :is_arith;
import :neg;
import :pad_front;
import :rem;
import :ssize;
import :str_num_config;
import :try_unsign;

export namespace xieite {
	template<xieite::is_arith T,
		xieite::end...,
		typename Radix = std::conditional_t<std::floating_point<T>, xieite::ssize, T>>
	[[nodiscard]] constexpr std::string str_num(T value, Radix radix = 10, xieite::str_num_config config = {}, std::size_t padding = 0) noexcept {
		std::string result;
		if (!radix || xieite::almost_eq(value, static_cast<T>(0))) {
			result += config.digits[0];
			if constexpr (std::floating_point<T>) {
				result += config.pts[0];
				result += config.digits[0];
			}
			return result;
		}
		const bool neg = xieite::neg(value);
		const xieite::try_unsign<T> abs = xieite::abs(value);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(abs), config.digits[1]);
		} else if (!std::unsigned_integral<T> && (radix == static_cast<Radix>(-1))) {
			result = config.digits[1];
			std::size_t length = static_cast<std::size_t>(abs);
			while (--length) {
				result += config.digits[0];
				result += config.digits[1];
			}
		} else {
			[[maybe_unused]] std::size_t point = 0;
			const auto next = [&value, radix, config, &result](Radix index) -> void {
				value = static_cast<T>(value / static_cast<T>(radix));
				if (xieite::neg(index)) {
					index = xieite::neg(radix) ? (index - radix) : (index + radix);
					++value;
				}
				result.insert(0, 1, config.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < config.digits.size())]);
			};
			if constexpr (std::floating_point<T>) {
				value = std::abs(value);
				do {
					value *= static_cast<T>(radix);
					++point;
				} while ((config.prec - point) && !xieite::almost_eq(std::fmod(value, 1), static_cast<T>(0)));
				value = std::round(value);
			} else {
				if (value == std::numeric_limits<T>::min()) {
					next(-static_cast<T>(value % radix));
				}
				value = static_cast<T>(xieite::abs(value));
			}
			while ((value >= 1) || (!std::unsigned_integral<T> && (value <= static_cast<T>(-1)))) {
				next(static_cast<Radix>(xieite::rem(value, static_cast<T>(radix))));
			}
			if constexpr (std::floating_point<T>) {
				if (point >= result.size()) {
					result.insert(0, point - result.size() + 1, config.digits[0]);
				}
				result.insert(result.size() - point, 1, config.pts[0]);
			}
		}
		if (neg) {
			result.insert(0, 1, config.neg[0]);
		}
		return xieite::pad_front(result, padding, config.digits[0]);
	}
}

export module xieite:num_str;

import std;
import :is_arith;
import :abs;
import :almost_eq;
import :neg;
import :rem;
import :ssize_if_float;
import :str_num_config;
import :try_unsigned;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr std::string stringify(T value, xieite::ssize_if_float<T> radix = 10, xieite::str_num_config config = {}) noexcept {
		using Radix = xieite::ssize_if_float<T>;
		std::string result;
		if (!radix || xieite::almost_eq(value, 0)) {
			result += config.digits[0];
			if constexpr (std::floating_point<T>) {
				result += config.points[0];
				result += config.digits[0];
			}
			return result;
		}
		const bool neg = xieite::neg(value);
		const xieite::try_unsigned<T> abs = xieite::abs(value);
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
			const auto next = [&value, radix, config, &result](Radix index) {
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
				} while ((config.precision - point) && !xieite::almost_eq(std::fmod(value, 1), 0));
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
				result.insert(result.size() - point, 1, config.points[0]);
			}
		}
		if (neg) {
			result.insert(0, 1, config.neg[0]);
		}
		return result;
	}
}

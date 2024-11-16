export module xieite:parse_num;

import std;
import :is_arith;
import :pow;
import :ssize;
import :split_bool;
import :str_num_cfg;

export namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T parse_num(std::string_view str, std::conditional_t<std::floating_point<T>, xieite::ssize, T> radix = 10, xieite::str_num_cfg config = {}) noexcept {
		if (!radix) {
			return 0;
		}
		const bool neg = config.neg.contains(str[0]);
		if constexpr (std::floating_point<T>) {
			T integral = 0;
			T fractional = 0;
			std::size_t point = 0;
			int pow = 0;
			for (std::size_t i = neg || config.pos.contains(str[0]); i < str.size(); ++i) {
				const std::size_t digit = config.digits.find(str[i]);
				if (digit == std::string::npos) {
					if (config.pts.contains(str[i])) {
						if (point) {
							break;
						}
						point = 1;
					} else if (config.exp.contains(str[i])) {
						pow = xieite::parse_num<int>(str.substr(i + 1), radix, config);
						break;
					}
					continue;
				}
				T& part = (point ? fractional : integral);
				part = part * static_cast<T>(radix) + static_cast<T>(digit);
				point += !!point;
			}
			return xieite::split_bool(!neg) * (integral + fractional / xieite::pow(radix, point - 1)) * xieite::pow(radix, pow);
		} else {
			T result = 0;
			for (std::size_t i = neg || config.pos.contains(str[0]); i < str.size(); ++i) {
				const std::size_t digit = config.digits.find(str[i]);
				if (digit == std::string::npos) {
					break;
				}
				result = static_cast<T>(result * static_cast<T>(radix) + static_cast<T>(digit));
			}
			return neg ? -result : result;
		}
	}
}

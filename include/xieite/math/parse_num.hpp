#pragma once

#include <concepts>
#include <cstddef>
#include <string>
#include <string_view>
#include <type_traits>
#include "../ctnr/num_str_config.hpp"
#include "../math/pow.hpp"
#include "../math/ssize_t.hpp"
#include "../math/split_bool.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T parse_num(std::string_view str, std::conditional_t<std::floating_point<T>, xieite::ssize_t, T> radix = 10, xieite::num_str_config config = {}) noexcept {
		if (!radix) {
			return 0;
		}
		const bool neg = config.minus.contains(str[0]);
		if constexpr (std::floating_point<T>) {
			T integral = 0;
			T fractional = 0;
			std::size_t point = 0;
			int pow = 0;
			for (std::size_t i = neg || config.plus.contains(str[0]); i < str.size(); ++i) {
				const std::size_t digit = config.digit.find(str[i]);
				if (digit == std::string::npos) {
					if (config.pt.contains(str[i])) {
						if (point) {
							break;
						}
						point = 1;
					} else if (config.e.contains(str[i])) {
						pow = xieite::parse_num<int>(str.substr(i + 1), radix, config);
						break;
					}
					continue;
				}
				T& part = (point ? fractional : integral);
				part = part * static_cast<T>(radix) + static_cast<T>(digit);
				point += !!point;
			}
			return xieite::split_bool(!neg) * (integral + fractional / xieite::pow(radix, static_cast<xieite::ssize_t>(point - 1))) * xieite::pow(radix, pow);
		} else {
			T result = 0;
			for (std::size_t i = neg || config.plus.contains(str[0]); i < str.size(); ++i) {
				const std::size_t digit = config.digit.find(str[i]);
				if (digit == std::string::npos) {
					break;
				}
				result = static_cast<T>(result * static_cast<T>(radix) + static_cast<T>(digit));
			}
			return neg ? -result : result;
		}
	}
}

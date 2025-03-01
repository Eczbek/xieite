#pragma once

#include <concepts>
#include <cstddef>
#include <string>
#include <string_view>
#include <type_traits>
#include "../ctnr/nstrcfg.hpp"
#include "../math/pow.hpp"
#include "../math/z.hpp"
#include "../math/splitb.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T parsen(std::string_view str, std::conditional_t<std::floating_point<T>, x4::z, T> radix = 10, x4::nstrcfg config = {}) noexcept {
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
						pow = x4::parsen<int>(str.substr(i + 1), radix, config);
						break;
					}
					continue;
				}
				T& part = (point ? fractional : integral);
				part = part * static_cast<T>(radix) + static_cast<T>(digit);
				point += !!point;
			}
			return x4::splitb(!neg) * (integral + fractional / x4::pow(radix, static_cast<x4::z>(point - 1))) * x4::pow(radix, pow);
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

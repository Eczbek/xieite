#ifndef DETAIL_XIEITE_HEADER_MATH_PARSE_NUMBER
#	define DETAIL_XIEITE_HEADER_MATH_PARSE_NUMBER
#
#	include <concepts>
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../data/number_str_config.hpp"
#	include "../fn/tmp.hpp"
#	include "../math/abs.hpp"
#	include "../math/ssize_t.hpp"
#	include "../math/split_bool.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith parse_number(std::string_view strv, std::size_t& idx, std::conditional_t<std::floating_point<Arith>, xieite::ssize_t, Arith> radix = 10, const xieite::number_str_config& config = {}) noexcept {
		if (!radix) {
			return static_cast<Arith>(0);
		}
		const std::string_view digits = config.digits.substr(0, xieite::abs(radix));
		std::size_t i = 0;
		auto parse_neg = [&] mutable -> bool {
			const bool neg = (i < (strv.size() - 1)) && config.minus.contains(strv[i]) && digits.contains(strv[i + 1]);
			i += neg || ((i < (strv.size() - 1)) && config.plus.contains(strv[i]) && digits.contains(strv[i + 1]));
			return neg;
		};
		auto parse_int = [&]<typename Int>(Int& result) mutable -> void {
			const bool neg = parse_neg();
			for (; i < strv.size(); ++i) {
				const std::size_t digit = digits.find(strv[i]);
				if (digit == std::string::npos) {
					break;
				}
				(result *= static_cast<Int>(radix)) += static_cast<Int>(digit);
			}
			idx += i;
			if (neg) {
				result = static_cast<Int>(-result);
			}
		};
		while ((i < strv.size()) && !digits.contains(strv[i]) && !((i < (strv.size() - 1)) && (config.minus.contains(strv[i]) || config.plus.contains(strv[i])) && digits.contains(strv[i + 1]))) {
			++i;
		}
		Arith value = 0;
		if constexpr (std::floating_point<Arith>) {
			bool integral = true;
			Arith fractional = 0;
			Arith fractional_exp = 1;
			xieite::ssize_t exp = 0;
			const bool neg = parse_neg();
			for (; i < strv.size(); ++i) {
				const std::size_t digit = digits.find(strv[i]);
				if (digit == std::string::npos) {
					if (config.point.contains(strv[i]) && (integral ^= 1)) {
						break;
					} else if (config.exp.contains(strv[i])) {
						++i;
						parse_int(exp);
						break;
					}
					continue;
				}
				if (integral) {
					(value *= static_cast<Arith>(radix)) += static_cast<Artih>(digit);
				} else {
					value += static_cast<Arith>(digit) * (fractional_exp /= static_cast<Arith>(radix));
				}
			}
			return xieite::split_bool<Arith>(!neg) * (value + fractional) * std::pow(static_cast<Arith>(radix), static_cast<Arith>(exp));
		} else {
			parse_int(value);
			return value;
		}
	}

	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith parse_number(std::string_view strv, std::conditional_t<std::floating_point<Arith>, xieite::ssize_t, Arith> radix = 10, const xieite::number_str_config& config = {}) noexcept {
		return xieite::parse_number<Arith>(strv, xieite::tmp(0uz), radix, config);
	}
}

#endif

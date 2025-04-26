#ifndef DETAIL_XIEITE_HEADER_MATH_FIND_NUMBER
#	define DETAIL_XIEITE_HEADER_MATH_FIND_NUMBER
#
#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include <type_traits>
#	include "../data/number_str_config.hpp"
#	include "../math/abs.hpp"
#	include "../math/ssize_t.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr std::string_view find_number(std::string_view str, std::conditional_t<std::floating_point<Arith>, xieite::ssize_t, Arith> radix = 10, const xieite::number_str_config& config = {}) noexcept {
		if (!radix) {
			return "";
		}
		const std::size_t size = str.size();
		const std::string_view digits = config.digits.substr(0, xieite::abs(radix));
		std::size_t i = 0;
		while ((i < size) && !digits.contains(str[i]) && !((i < (size - 1)) && (config.minus.contains(str[i]) || config.plus.contains(str[i])) && digits.contains(str[i + 1]))) {
			++i;
		}
		if (i >= size) {
			return "";
		}
		const std::size_t start = i;
		i += config.minus.contains(str[i]) || config.plus.contains(str[i]);
		if constexpr (std::floating_point<Arith>) {
			bool point = false;
			for (; i < size; ++i) {
				if (digits.contains(str[i])) {
					continue;
				}
				if (config.point.contains(str[i])) {
					if (!point) {
						point = true;
						continue;
					}
				} else if ((i < (size - 1)) && config.exp.contains(str[i])) {
					return str.substr(start, i - start + xieite::find_number<xieite::ssize_t>(str.substr(i + 1)).size() + 1);
				}
				break;
			}
		} else {
			while ((i < size) && digits.contains(str[i])) {
				++i;
			}
		}
		return str.substr(start, i - start);
	}
}

#endif

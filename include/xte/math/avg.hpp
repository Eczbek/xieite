#ifndef DETAIL_XTE_HEADER_MATH_AVG
#	define DETAIL_XTE_HEADER_MATH_AVG
#
#	include "../math/abs.hpp"
#	include "../math/diff.hpp"
#	include "../math/div.hpp"
#	include "../math/div_trunc_half.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/numbers.hpp"
#	include <type_traits>

namespace xte {
	[[nodiscard]] constexpr auto avg(xte::is_number auto first, xte::is_number auto... rest) noexcept {
		if constexpr (using common_type = std::common_type_t<decltype(first), decltype(rest)...>; xte::is_float<common_type>) {
			static constexpr auto count = static_cast<common_type>(sizeof...(rest) + 1);
			return ((first / count) + ... + (rest / count));
		} else {
			using unsigned_type = std::make_unsigned_t<common_type>;
			auto avg = static_cast<unsigned_type>(xte::abs(first));
			auto sign = xte::sign(first);
			xte::uz count = 1;
			unsigned_type tmp = 0;
			(void)(..., (++count, (xte::sign(sign, rest) < 0) ? (((tmp = static_cast<unsigned_type>(xte::div(avg, count) + xte::div(xte::abs(rest), count) + ((avg % count) >= (count - xte::abs(rest) % count)))) > avg) && (sign *= -1), avg = xte::diff(avg, tmp)) : (avg += static_cast<unsigned_type>(static_cast<unsigned_type>(sign) * xte::div_trunc_half(xte::diff(xte::abs(rest), avg), count)))));
			return static_cast<common_type>(avg * static_cast<unsigned_type>(sign));
		}
	}
}

#endif

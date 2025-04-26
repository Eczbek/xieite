#ifndef DETAIL_XIEITE_HEADER_MATH_LOG
#	define DETAIL_XIEITE_HEADER_MATH_LOG
#
#	include <cmath>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, xieite::is_arith Result = std::common_type_t<Arith, double>>
	[[nodiscard]] constexpr Result log(Arith base, Arith x) noexcept {
		return static_cast<Result>(std::log(x) / std::log(base));
	}
}

#endif

// https://quick-bench.com/q/ZhKXMlnjYG6n-xrgtAtjy6kYPFc

#ifndef DETAIL_XIEITE_HEADER_MATH_FACTORIAL
#	define DETAIL_XIEITE_HEADER_MATH_FACTORIAL
#
#	include <cstddef>
#	include <vector>
#	include "../data/make_array.hpp"
#	include "../math/mul_overflow.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	constexpr auto factorial = ([] static {
		static constexpr auto get = [] static -> std::vector<Arith> {
			std::vector<Arith> result = { 1 };
			for (std::size_t i = 1; !xieite::mul_overflow(static_cast<Arith>(i), result[i - 1]); ++i) {
				result.push_back(static_cast<Arith>(i) * result[i - 1]);
			}
			return result;
		};
		return xieite::make_array<Arith, get().size()>(get());
	})();
}

#endif

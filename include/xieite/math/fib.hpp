#ifndef DETAIL_XIEITE_HEADER_MATH_FIB
#	define DETAIL_XIEITE_HEADER_MATH_FIB
#
#	include <cstddef>
#	include <vector>
#	include "../data/make_array.hpp"
#	include "../math/add_overflow.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	constexpr auto fib = ([] static {
		static constexpr auto get = [] static -> std::vector<Arith> {
			std::vector<Arith> result = { 0, 1 };
			for (std::size_t i = 2; !xieite::add_overflow(result[i - 1], result[i - 2]); ++i) {
				result.push_back(result[i - 1] + result[i - 2]);
			}
			return result;
		};
		return xieite::make_array<Arith, get().size()>(get());
	})();
}

#endif

#ifndef DETAIL_XIEITE_HEADER_MATH_LEAST_UINT
#	define DETAIL_XIEITE_HEADER_MATH_LEAST_UINT
#
#	include <cstddef>
#	include <cstdint>
#	include "../math/bit_size.hpp"
#	include "../meta/type_list.hpp"

namespace xieite {
	template<std::size_t bits>
	using least_uint = xieite::type_list<
		std::uint_least8_t,
		std::uint_least16_t,
		std::uint_least32_t,
		std::uint_least64_t
	>::find<[]<typename Int> requires(xieite::bit_size<Int> >= bits) {}>;
}

#endif

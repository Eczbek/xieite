#ifndef DETAIL_XIEITE_HEADER_MATH_LEAST_INT
#	define DETAIL_XIEITE_HEADER_MATH_LEAST_INT
#
#	include <cstddef>
#	include <type_traits>
#	include "../math/least_uint.hpp"

namespace xieite {
	template<std::size_t bits>
	using least_int = std::make_signed_t<xieite::least_uint<bits>>;
}

#endif

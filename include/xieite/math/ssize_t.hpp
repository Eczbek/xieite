#ifndef DETAIL_XIEITE_HEADER_MATH_SSIZE_T
#	define DETAIL_XIEITE_HEADER_MATH_SSIZE_T
#
#	include <cstddef>
#	include <type_traits>

namespace xieite {
	using ssize_t = std::make_signed_t<std::size_t>;
}

#endif

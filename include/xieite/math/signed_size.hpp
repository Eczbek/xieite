#ifndef XIEITE_HEADER_MATH_SIGNED_SIZE
#	define XIEITE_HEADER_MATH_SIGNED_SIZE

#	include <cstddef>
#	include <type_traits>

namespace xieite::math {
	using SignedSize = std::make_signed_t<std::size_t>;
}

#endif

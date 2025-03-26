#ifndef DETAIL_XIEITE_HEADER_FN_CAST
#	define DETAIL_XIEITE_HEADER_FN_CAST
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename T>
	constexpr auto cast =
		[][[nodiscard]](auto&& x) static
			XIEITE_ARROW(static_cast<T>(XIEITE_FWD(x)));
}

#endif

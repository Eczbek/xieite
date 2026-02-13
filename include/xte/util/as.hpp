#ifndef DETAIL_XTE_HEADER_UTIL_AS
#	define DETAIL_XTE_HEADER_UTIL_AS
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"

namespace xte {
	template<typename T>
	constexpr auto as = [][[nodiscard]](auto&& x) static XTE_ARROW(
		static_cast<T>(XTE_FWD(x))
	);
}

#endif

#ifndef DETAIL_XTE_HEADER_UTIL_AS
#	define DETAIL_XTE_HEADER_UTIL_AS
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/at.hpp"

namespace xte {
	template<typename T>
	constexpr auto as = [][[nodiscard]](auto&&... args) static XTE_ARROW_CHOOSE(
		(sizeof...(args) == 1),
		static_cast<T>(xte::at<0>(XTE_FWD(args)...)),
		T(XTE_FWD(args)...)
	);
}

#endif

#ifndef DETAIL_XIEITE_HEADER_PP_AS
#	define DETAIL_XIEITE_HEADER_PP_AS
#
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#
#	define XIEITE_AS(...) ->*DETAIL_XIEITE::AS::impl<__VA_ARGS__>()

namespace DETAIL_XIEITE::AS {
	template<typename T>
	struct impl {
		[[nodiscard]] friend constexpr auto operator->*(auto&& x, DETAIL_XIEITE::AS::impl<T>)
			XIEITE_ARROW(static_cast<T>(XIEITE_FWD(x)))
	};
}

#endif

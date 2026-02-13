#ifndef DETAIL_XTE_HEADER_PREPROC_AS
#	define DETAIL_XTE_HEADER_PREPROC_AS
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#
#	define XTE_AS(...) ->*DETAIL_XTE::AS<__VA_ARGS__>()

namespace DETAIL_XTE {
	template<typename T>
	struct AS {
		[[nodiscard]] friend constexpr auto operator->*(auto&& x, DETAIL_XTE::AS<T>) XTE_ARROW(
			static_cast<T>(XTE_FWD(x))
		)
	};
}

#endif

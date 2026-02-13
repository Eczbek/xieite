#ifndef DETAIL_XTE_HEADER_FUNC_WITH_RESULT
#	define DETAIL_XTE_HEADER_FUNC_WITH_RESULT
#
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_callable.hpp"

namespace DETAIL_XTE {
	template<typename Func>
	struct with_result {
		Func&& func;

		[[nodiscard]] explicit constexpr with_result(Func&& func) XTE_ARROW_CTOR(,
			func,((XTE_FWD(func)))
		)

		XTE_ARROW_CAST([[nodiscard]] constexpr, auto&& self, XTE_FWD(self).func())
	};
}

namespace xte {
	inline constexpr auto with_result = [][[nodiscard]](xte::is_callable<void()> auto&& func) static XTE_ARROW(
		DETAIL_XTE::with_result<decltype(func)>(XTE_FWD(func))
	);
}

#endif

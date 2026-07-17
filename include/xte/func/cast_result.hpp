#ifndef DETAIL_XTE_HEADER_FUNC_CAST_RESULT
#	define DETAIL_XTE_HEADER_FUNC_CAST_RESULT
#
#	include "../preproc/define_cast.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_callable.hpp"

namespace DETAIL_XTE::cast_result {
	template<typename Func>
	struct impl {
		Func&& func;

		[[nodiscard]] explicit constexpr impl(Func&& func) XTE_CONSTRUCTS(,
			func,((XTE_FWD(func)))
		)

		XTE_DEFINE_CAST([[nodiscard]] constexpr, auto&& self,
			XTE_FWD(self).func()
		)
	};
}

namespace xte {
	inline constexpr auto cast_result = [][[nodiscard]](xte::is_callable<void()> auto&& func) static XTE_RETURNS(
		DETAIL_XTE::cast_result::impl<decltype(func)>(XTE_FWD(func))
	);
}

#endif

#ifndef DETAIL_XTE_HEADER_MATH_MIN
#	define DETAIL_XTE_HEADER_MATH_MIN
#
#	include "../math/less.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/assign.hpp"
#	include <type_traits>

namespace xte {
	template<typename T, typename... Ts,
		typename common_type = std::common_type_t<T, Ts...>>
	[[nodiscard]] constexpr common_type min(T&& x, Ts&&... ys)
	noexcept(noexcept(static_cast<common_type>(XTE_FWD(x)))
		&& (... && (noexcept(xte::less(ys, xte::fake<common_type&>()))
			&& noexcept(xte::assign(xte::fake<common_type&>(), XTE_FWD(ys))))))
	requires(requires { static_cast<common_type>(XTE_FWD(x)); }
		&& (... && requires (common_type min) {
			xte::less(ys, min);
			xte::assign(min, XTE_FWD(ys));
		}))
	{
		auto min = static_cast<common_type>(XTE_FWD(x));
		(void)(..., (xte::less(ys, min) ? xte::assign(min, XTE_FWD(ys)) : min));
		return min;
	}
}

#endif

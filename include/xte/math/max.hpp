#ifndef DETAIL_XTE_HEADER_MATH_MAX
#	define DETAIL_XTE_HEADER_MATH_MAX
#
#	include "../math/less.hpp"
#	include "../meta/fake.hpp"
#	include "../preproc/fwd.hpp"
#	include "../util/assign.hpp"
#	include <type_traits>

namespace xte {
	template<typename T, typename... Ts,
		typename common_type = std::common_type_t<T, Ts...>>
	[[nodiscard]] constexpr common_type max(T&& x, Ts&&... ys)
	noexcept(noexcept(static_cast<common_type>(XTE_FWD(x)))
		&& (... && (noexcept(xte::less(ys, xte::fake<common_type&>()))
			&& noexcept(xte::assign(xte::fake<common_type&>(), XTE_FWD(ys))))))
	requires(requires { static_cast<common_type>(XTE_FWD(x)); }
		&& (... && requires (common_type max) {
			xte::less(ys, max);
			xte::assign(max, XTE_FWD(ys));
		}))
	{
		auto max = static_cast<common_type>(XTE_FWD(x));
		(void)(..., (xte::less(max, ys) ? xte::assign(max, XTE_FWD(ys)) : max));
		return max;
	}
}

#endif

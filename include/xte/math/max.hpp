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
	[[nodiscard]] constexpr common_type max(T&& first, Ts&&... rest)
	noexcept(noexcept(static_cast<common_type>(XTE_FWD(first)))
		&& (... && (noexcept(xte::less(rest, xte::fake<common_type&>()))
			&& noexcept(xte::assign(xte::fake<common_type&>(), XTE_FWD(rest))))))
	requires(requires { static_cast<common_type>(XTE_FWD(first)); }
		&& (... && requires (common_type max) {
			xte::less(rest, max);
			xte::assign(max, XTE_FWD(rest));
		}))
	{
		auto max = static_cast<common_type>(XTE_FWD(first));
		(void)(..., (xte::less(max, rest) ? xte::assign(max, XTE_FWD(rest)) : max));
		return max;
	}
}

#endif

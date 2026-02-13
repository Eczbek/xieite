#ifndef DETAIL_XTE_HEADER_UTIL_IMPLICITLY
#	define DETAIL_XTE_HEADER_UTIL_IMPLICITLY
#
#	include "../preproc/fwd.hpp"
#	include "../trait/is_implicit_castable.hpp"
#	include "../trait/is_noex_implicit_castable.hpp"

namespace xte {
	template<typename T>
	constexpr auto implicitly = [][[nodiscard]](xte::is_implicit_castable<T> auto&& x) static noexcept(xte::is_noex_implicit_castable<decltype(x)&&, T>) -> T {
		return XTE_FWD(x);
	};
}

#endif

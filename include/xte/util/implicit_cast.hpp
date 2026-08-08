#ifndef DETAIL_XTE_HEADER_UTIL_IMPLICIT_CAST
#	define DETAIL_XTE_HEADER_UTIL_IMPLICIT_CAST
#
#	include "../preproc/fwd.hpp"
#	include "../trait/is_castable_implicit.hpp"
#	include "../trait/is_castable_implicit_noex.hpp"

namespace xte {
	template<typename T>
	constexpr auto implicit_cast = [][[nodiscard]](xte::is_castable_implicit<T> auto&& x) static noexcept(xte::is_castable_implicit_noex<decltype(x)&&, T>) -> T {
		return XTE_FWD(x);
	};
}

#endif

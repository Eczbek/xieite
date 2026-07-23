#ifndef DETAIL_XTE_HEADER_UTIL_AS
#	define DETAIL_XTE_HEADER_UTIL_AS
#
#	include "../preproc/fwd.hpp"
#	include "../trait/copy_cvref.hpp"

namespace xte {
	template<typename T>
	constexpr auto as = [][[nodiscard]](auto&& x) static noexcept -> auto&& {
		return const_cast<xte::copy_cvref<T&&, decltype(x)>>(x);
	};
}

#endif

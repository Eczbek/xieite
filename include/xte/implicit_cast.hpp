#ifndef DETAIL_XTE_HEADER_IMPLICIT_CAST
#	define DETAIL_XTE_HEADER_IMPLICIT_CAST
#
#	include "./class_traits.hpp"
#	include "./macros.hpp"

namespace xte {
	template<typename target_type>
	constexpr auto implicit_cast =
		[][[nodiscard]](xte::is_implicitly_convertible<target_type> auto&& x) static
		noexcept(xte::is_implicitly_convertible_noex<decltype(x)&&, target_type>)
		-> target_type {
			return XTE_FWD(x);
		};
}

#endif

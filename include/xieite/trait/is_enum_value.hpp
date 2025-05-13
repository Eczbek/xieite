#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ENUM_VALUE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ENUM_VALUE
#
#	include <concepts>
#	include "../meta/obj_name.hpp"
#	include "../trait/is_enum.hpp"

namespace xieite {
	template<auto x, typename Enum>
	concept is_enum_value =
		xieite::is_enum<Enum>
		&& requires { ([]<std::integral auto y, auto = static_cast<Enum>(y)> {}).template operator()<x>(); }
		&& (xieite::obj_name<static_cast<Enum>(x)>[0] != '(');
}

#endif

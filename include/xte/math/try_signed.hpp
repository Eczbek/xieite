#ifndef DETAIL_XTE_HEADER_MATH_TRY_SIGNED
#	define DETAIL_XTE_HEADER_MATH_TRY_SIGNED
#
#	include "../trait/is_unsigned.hpp"
#	include "../meta/type_at.hpp"
#	include "../meta/wrap_type.hpp"
#	include <type_traits>

namespace xte {
	template<typename T>
	using try_signed = xte::type_at<xte::is_unsigned<T>, xte::wrap_type<T>, std::make_signed<T>>::type;
}

#endif

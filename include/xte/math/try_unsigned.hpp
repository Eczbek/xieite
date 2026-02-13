#ifndef DETAIL_XTE_HEADER_MATH_TRY_UNSIGNED
#	define DETAIL_XTE_HEADER_MATH_TRY_UNSIGNED
#
#	include "../trait/is_signed.hpp"
#	include "../meta/type_at.hpp"
#	include "../meta/wrap_type.hpp"
#	include <type_traits>

namespace xte {
	template<typename T>
	using try_unsigned = xte::type_at<xte::is_signed<T>, xte::wrap_type<T>, std::make_unsigned<T>>::type;
}

#endif

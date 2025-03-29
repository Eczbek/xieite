#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VARIADIC_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VARIADIC_REFERENT
#
#	include <type_traits>
#	include "../trait/add_variadic_referent.hpp"
#	include "../trait/rm_variadic_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_variadic_referent = std::conditional_t<qual, xieite::add_variadic_referent<T>, xieite::rm_variadic_referent<T>>;
}

#endif

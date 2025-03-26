#ifndef DETAIL_XIEITE_HEADER_TRAIT_TRY_SIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_TRY_SIGN
#
#	include <type_traits>
#	include "../trait/is_unsign.hpp"

namespace xieite {
	template<typename T>
	using try_sign = std::conditional_t<xieite::is_unsign<T>, std::make_signed<T>, std::type_identity<T>>::type;
}

#endif

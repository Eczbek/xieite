#ifndef DETAIL_XIEITE_HEADER_TRAIT_TRY_SIGNED
#	define DETAIL_XIEITE_HEADER_TRAIT_TRY_SIGNED
#
#	include <type_traits>
#	include "../trait/is_unsigned.hpp"

namespace xieite {
	template<typename T>
	using try_signed = std::conditional_t<xieite::is_unsigned<T>, std::make_signed<T>, std::type_identity<T>>::type;
}

#endif

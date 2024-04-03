#ifndef XIEITE_HEADER_TYPES_MAYBE_SIGNED
#	define XIEITE_HEADER_TYPES_MAYBE_SIGNED

#	include <type_traits>
#	include "../concepts/integral.hpp"

namespace xieite::types {
	template<xieite::concepts::Integral Integral_, bool signed_>
	using MaybeSigned = std::conditional_t<signed_, std::make_signed<Integral_>, std::make_unsigned<Integral_>>::type;
}

#endif

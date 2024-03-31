#ifndef XIEITE_HEADER_TYPES_MAYBE_SIGNED
#	define XIEITE_HEADER_TYPES_MAYBE_SIGNED

#	include <type_traits>
#	include "../concepts/unsigned_integer.hpp"

namespace xieite::types {
	template<typename Type>
	using MaybeSigned = std::conditional_t<xieite::concepts::UnsignedIntegral<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
}

#endif

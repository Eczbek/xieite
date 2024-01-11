#ifndef XIEITE_HEADER_TYPES_CONDITIONALLY_SIGN
#	define XIEITE_HEADER_TYPES_CONDITIONALLY_SIGN

#	include <type_traits>
#	include "../concepts/integer.hpp"

namespace xieite::types {
	template<xieite::concepts::Integer Integer, bool sign>
	using ConditionallySigned = std::conditional_t<sign, std::make_signed_t<Integer>, std::make_unsigned_t<Integer>>;
}

#endif

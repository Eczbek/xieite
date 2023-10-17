#ifndef XIEITE_HEADER_TYPES_MAYBE_UNSIGNED
#	define XIEITE_HEADER_TYPES_MAYBE_UNSIGNED

#	include <concepts>
#	include <type_traits>

namespace xieite::types {
	template<typename Type>
	using MaybeUnsigned = std::conditional_t<std::signed_integral<Type>, std::make_unsigned<Type>, std::type_identity<Type>>::type;
}

#endif

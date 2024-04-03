#ifndef XIEITE_HEADER_TYPES_TRY_UNSIGNED
#	define XIEITE_HEADER_TYPES_TRY_UNSIGNED

#	include <concepts>
#	include <type_traits>

namespace xieite::types {
	template<typename Type_>
	using TryUnsigned = std::conditional_t<std::signed_integral<Type_>, std::make_unsigned<Type_>, std::type_identity<Type_>>::type;
}

#endif

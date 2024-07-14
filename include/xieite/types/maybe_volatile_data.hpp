#ifndef XIEITE_HEADER_TYPES_MAYBE_VOLATILE_DATA
#   define XIEITE_HEADER_TYPES_MAYBE_VOLATILE_DATA

#   include <type_traits>
#   include "../types/maybe_volatile.hpp"

namespace xieite::detail {
	template<typename, bool>
	struct MaybeVolatileData;

	template<typename Type_, bool volatile_>
	struct MaybeVolatileData<Type_*, volatile_>
	: std::type_identity<xieite::types::MaybeVolatile<Type_, volatile_>*> {};

	template<typename Type_, bool volatile_>
	struct MaybeVolatileData<Type_&, volatile_>
	: std::type_identity<xieite::types::MaybeVolatile<Type_, volatile_>&> {};

	template<typename Type_, bool volatile_>
	struct MaybeVolatileData<Type_&&, volatile_>
	: std::type_identity<xieite::types::MaybeVolatile<Type_, volatile_>&&> {};
}

namespace xieite::types {
	template<typename Type_, bool volatile_>
	requires(std::is_pointer_v<Type_> || std::is_reference_v<Type_>)
	using MaybeVolatileData = xieite::detail::MaybeVolatileData<Type_, volatile_>::type;
}

#endif

#ifndef XIEITE_HEADER_TYPES_MAYBE_VOLATILE_DATA
#   define XIEITE_HEADER_TYPES_MAYBE_VOLATILE_DATA

#   include <type_traits>
#   include "../types/maybe_volatile.hpp"

namespace xieite::detail {
	template<typename, bool>
	struct MaybeVolatileData;

	template<typename Type, bool volatileQualified>
	struct MaybeVolatileData<Type*, volatileQualified>
	: std::type_identity<xieite::types::MaybeVolatile<Type, volatileQualified>*> {};

	template<typename Type, bool volatileQualified>
	struct MaybeVolatileData<Type&, volatileQualified>
	: std::type_identity<xieite::types::MaybeVolatile<Type, volatileQualified>&> {};

	template<typename Type, bool volatileQualified>
	struct MaybeVolatileData<Type&&, volatileQualified>
	: std::type_identity<xieite::types::MaybeVolatile<Type, volatileQualified>&&> {};
}

namespace xieite::types {
	template<typename Type, bool volatileQualified>
	requires(std::is_pointer_v<Type> || std::is_reference_v<Type>)
	using MaybeVolatileData = xieite::detail::MaybeVolatileData<Type, volatileQualified>::type;
}

#endif

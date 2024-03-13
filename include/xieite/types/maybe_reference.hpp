#ifndef XIEITE_HEADER_TYPES_MAYBE_REFERENCE
#	define XIEITE_HEADER_TYPES_MAYBE_REFERENCE

#	include <cstddef>
#	include <type_traits>

namespace xieite::types {
	template<typename Type>
	using MaybeReference = std::conditional_t<(sizeof(Type) <= sizeof(std::size_t)) && std::is_trivially_copyable_v<Type>, Type, Type&>;
}

#endif

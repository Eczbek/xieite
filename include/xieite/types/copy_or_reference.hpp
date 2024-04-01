#ifndef XIEITE_HEADER_TYPES_COPY_OR_REFERENCE
#	define XIEITE_HEADER_TYPES_COPY_OR_REFERENCE

#	include <cstddef>
#	include <type_traits>

namespace xieite::types {
	template<typename Type>
	using CopyOrReference = std::conditional_t<(sizeof(Type) <= sizeof(std::size_t)) && std::is_trivially_copyable_v<Type>, std::remove_reference<Type>, std::add_lvalue_reference<Type>>::type;
}

#endif

#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT_DATA
#   define XIEITE_HEADER_TYPES_MAYBE_CONSTANT_DATA

#   include <type_traits>
#	include <type_traits>
#   include "../types/maybe_constant.hpp"

namespace xieite::detail {
	template<typename, bool>
	struct MaybeConstantData;

	template<typename Type, bool constantQualified>
	struct MaybeConstantData<Type*, constantQualified>
	: std::type_identity<xieite::types::MaybeConstant<Type, constantQualified>*> {};

	template<typename Type, bool constantQualified>
	struct MaybeConstantData<Type&, constantQualified>
	: std::type_identity<xieite::types::MaybeConstant<Type, constantQualified>&> {};

	template<typename Type, bool constantQualified>
	struct MaybeConstantData<Type&&, constantQualified>
	: std::type_identity<xieite::types::MaybeConstant<Type, constantQualified>&&> {};
}

namespace xieite::types {
	template<typename Type, bool constantQualified>
	requires(std::is_pointer_v<Type> || std::is_reference_v<Type>)
	using MaybeConstantData = xieite::detail::MaybeConstantData<Type, constantQualified>::type;
}

#endif

#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT_DATA
#   define XIEITE_HEADER_TYPES_MAYBE_CONSTANT_DATA

#   include <type_traits>
#   include "../types/maybe_constant.hpp"
#   include "../types/type_wrapper.hpp"

namespace xieite::detail {
	template<typename, bool>
	struct MaybeConstantData;

	template<typename Type_, bool constant_>
	struct MaybeConstantData<Type_*, constant_>
	: xieite::types::TypeWrapper<xieite::types::MaybeConstant<Type_, constant_>*> {};

	template<typename Type_, bool constant_>
	struct MaybeConstantData<Type_&, constant_>
	: xieite::types::TypeWrapper<xieite::types::MaybeConstant<Type_, constant_>&> {};

	template<typename Type_, bool constant_>
	struct MaybeConstantData<Type_&&, constant_>
	: xieite::types::TypeWrapper<xieite::types::MaybeConstant<Type_, constant_>&&> {};
}

namespace xieite::types {
	template<typename Type_, bool constant_>
	requires(std::is_pointer_v<Type_> || std::is_reference_v<Type_>)
	using MaybeConstantData = xieite::detail::MaybeConstantData<Type_, constant_>::Type;
}

#endif

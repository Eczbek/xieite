#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT
#	define XIEITE_HEADER_TYPES_MAYBE_CONSTANT

#	include <type_traits>
#	include "../types/copy_reference.hpp"

namespace xieite::types {
	template<typename Type, bool qualified>
	using MaybeConstant = xieite::types::CopyReference<Type, std::conditional_t<qualified, const std::remove_reference_t<Type>, std::remove_const_t<std::remove_reference_t<Type>>>>;
}

#endif

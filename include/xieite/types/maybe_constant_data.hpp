#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT_DATA
#	define XIEITE_HEADER_TYPES_MAYBE_CONSTANT_DATA

#	include "../concepts/pointer.hpp"
#	include "../types/maybe_constant.hpp"
#	include "../types/maybe_pointer.hpp"

namespace xieite::types {
	template<xieite::concepts::Pointer Type, bool qualified>
	using MaybeConstantData = xieite::types::MaybePointer<xieite::types::MaybeConstant<xieite::types::MaybePointer<Type, false>, qualified>, true>;
}

#endif

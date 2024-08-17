#ifndef XIEITE_HEADER_TYPES_MAYBE_VOLATILE_DATA
#	define XIEITE_HEADER_TYPES_MAYBE_VOLATILE_DATA

#	include "../concepts/pointer.hpp"
#	include "../types/maybe_pointer.hpp"
#	include "../types/maybe_volatile.hpp"

namespace xieite::types {
	template<xieite::concepts::Pointer Type, bool qualified>
	using MaybeVolatileData = xieite::types::MaybePointer<xieite::types::MaybeVolatile<xieite::types::MaybePointer<Type, false>, qualified>, true>;
}

#endif

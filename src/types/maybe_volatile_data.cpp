export module xieite:types.MaybeVolatileData;

import :concepts.Pointer;
import :types.MaybePointer;
import :types.MaybeVolatile;

export namespace xieite::types {
	template<xieite::concepts::Pointer Type, bool qualified>
	using MaybeVolatileData = xieite::types::MaybePointer<xieite::types::MaybeVolatile<xieite::types::MaybePointer<Type, false>, qualified>, true>;
}

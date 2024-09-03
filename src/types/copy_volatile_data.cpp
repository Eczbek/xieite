export module xieite:types.CopyVolatileData;

import :concepts.Pointer;
import :concepts.Volatile;
import :types.MaybeVolatileData;

export namespace xieite::types {
	template<typename Source, xieite::concepts::Pointer Target>
	using CopyVolatileData = xieite::types::MaybeVolatileData<Target, xieite::concepts::Volatile<Source>>;
}

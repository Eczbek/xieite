export module xieite:types.CopyVolatile;

import :concepts.Volatile;
import :types.MaybeVolatile;

export namespace xieite::types {
	template<typename Source, typename Target>
	using CopyVolatile = xieite::types::MaybeVolatile<Target, xieite::concepts::Volatile<Source>>;
}

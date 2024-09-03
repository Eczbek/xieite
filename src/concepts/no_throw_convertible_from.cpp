export module xieite:concepts.NoThrowConvertibleFrom;

import :concepts.NoThrowConvertibleTo;

export namespace xieite::concepts {
	template<typename Target, typename Source>
	concept NoThrowConvertibleFrom = xieite::concepts::NoThrowConvertibleTo<Source, Target>;
}

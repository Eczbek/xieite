export module xieite:concepts.NoThrowConvertibleToAny;

import :concepts.NoThrowConvertibleTo;

export namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAny = (... || xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
}

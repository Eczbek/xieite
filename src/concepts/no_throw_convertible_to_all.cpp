export module xieite:concepts.NoThrowConvertibleToAll;

import :concepts.NoThrowConvertibleTo;

export namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAll = (... && xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
}

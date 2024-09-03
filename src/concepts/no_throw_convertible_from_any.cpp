export module xieite:concepts.NoThrowConvertibleFromAny;

import :concepts.NoThrowConvertibleFrom;

export namespace xieite::concepts {
	template<typename Target, typename... Sources>
	concept NoThrowConvertibleFromAny = (... && xieite::concepts::NoThrowConvertibleFrom<Target, Sources>);
}

export module xieite:concepts.NoThrowConvertibleFromAll;

import :concepts.NoThrowConvertibleFrom;

export namespace xieite::concepts {
	template<typename Target, typename... Sources>
	concept NoThrowConvertibleFromAll = (... && xieite::concepts::NoThrowConvertibleFrom<Target, Sources>);
}

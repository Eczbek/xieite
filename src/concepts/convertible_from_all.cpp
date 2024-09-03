export module xieite:concepts.ConvertibleFromAll;

import :concepts.ConvertibleFrom;

export namespace xieite::concepts {
	template<typename Target, typename... Sources>
	concept ConvertibleFromAll = (... && xieite::concepts::ConvertibleFrom<Target, Sources>);
}

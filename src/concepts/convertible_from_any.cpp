export module xieite:concepts.ConvertibleFromAny;

import :concepts.ConvertibleFrom;

export namespace xieite::concepts {
	template<typename Target, typename... Sources>
	concept ConvertibleFromAny = (... || xieite::concepts::ConvertibleFrom<Target, Sources>);
}

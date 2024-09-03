export module xieite:concepts.ConvertibleToAny;

import std;

export namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAny = (... || std::convertible_to<Source, Targets>);
}

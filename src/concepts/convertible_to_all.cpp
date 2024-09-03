export module xieite:concepts.ConvertibleToAll;

import std;

export namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAll = (... && std::convertible_to<Source, Targets>);
}

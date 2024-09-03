export module xieite:concepts.ConvertibleFrom;

import std;

export namespace xieite::concepts {
	template<typename Target, typename Source>
	concept ConvertibleFrom = std::convertible_to<Source, Target>;
}

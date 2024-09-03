export module xieite:concepts.DerivedFromAny;

import std;

export namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAny = (... || std::derived_from<Derived, Bases>);
}

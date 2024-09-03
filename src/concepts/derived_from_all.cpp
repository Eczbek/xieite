export module xieite:concepts.DerivedFromAll;

import std;

export namespace xieite::concepts {
	template<typename Derived, typename... Bases>
	concept DerivedFromAll = (... && std::derived_from<Derived, Bases>);
}

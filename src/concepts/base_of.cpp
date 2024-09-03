export module xieite:concepts.BaseOf;

import std;

export namespace xieite::concepts {
	template<typename Base, typename Derived>
	concept BaseOf = std::derived_from<Derived, Base>;
}

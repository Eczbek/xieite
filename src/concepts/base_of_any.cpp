export module xieite:concepts.BaseOfAny;

import :concepts.BaseOf;

export namespace xieite::concepts {
	template<typename Base, typename... Derived>
	concept BaseOfAny = (... || xieite::concepts::BaseOf<Base, Derived>);
}

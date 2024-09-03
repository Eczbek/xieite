export module xieite:concepts.BaseOfAll;

import :concepts.BaseOf;

export namespace xieite::concepts {
	template<typename Base, typename... Derived>
	concept BaseOfAll = (... && xieite::concepts::BaseOf<Base, Derived>);
}

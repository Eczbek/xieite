export module xieite:traits.IsDerivedFrom;

import std;

export namespace xieite::traits {
	template<typename Derived, typename Base>
	struct IsDerivedFrom
	: std::bool_constant<std::derived_from<Derived, Base>> {};
}

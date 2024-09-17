export module xieite:containers.CopyDefaultConstructible;

import std;
import :containers.MaybeDefaultConstructible;

export namespace xieite::containers {
	template<typename Type>
	using CopyDefaultConstructible = xieite::containers::MaybeDefaultConstructible<std::is_default_constructible_v<Type>>;
}

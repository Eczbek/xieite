export module xieite:concepts.CopyConstructible;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept CopyConstructible = std::is_copy_constructible_v<Type>;
}

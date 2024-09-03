export module xieite:concepts.Polymorphic;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Polymorphic = std::is_polymorphic_v<Type>;
}

export module xieite:concepts.LeftValueReference;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept LeftValueReference = std::is_lvalue_reference_v<Type>;
}

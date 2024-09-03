export module xieite:concepts.RightValueReference;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept RightValueReference = std::is_rvalue_reference_v<Type>;
}

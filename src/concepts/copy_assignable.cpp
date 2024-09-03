export module xieite:concepts.CopyAssignable;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept CopyAssignable = std::is_copy_assignable_v<Type>;
}

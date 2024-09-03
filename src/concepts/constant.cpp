export module xieite:concepts.Constant;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Constant = std::is_const_v<std::remove_reference_t<Type>>;
}

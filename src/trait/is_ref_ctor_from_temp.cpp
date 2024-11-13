export module xieite:is_ref_ctor_from_temp;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_ref_ctor_from_temp = std::reference_constructs_from_temporary_v<T, U>;
}

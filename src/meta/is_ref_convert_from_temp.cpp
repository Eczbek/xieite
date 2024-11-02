export module xieite:is_ref_convert_from_temp;

import std;

export namespace xieite {
	template<typename T>
	concept is_ref_convert_from_temp = std::reference_converts_from_temporary_v<T>;
}

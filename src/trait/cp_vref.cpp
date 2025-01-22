export module xieite:cp_vref;

import :cp_ref;
import :cp_v;

export namespace xieite {
	template<typename T, typename U>
	using cp_vref = xieite::cp_v<T, xieite::cp_ref<T, U>>;
}

export module xieite:add_v;

import :cp_ref;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using add_v = xieite::cp_ref<T, volatile xieite::rm_ref<T>>;
}

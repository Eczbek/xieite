export module xieite:add_c;

import :cp_ref;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using add_c = xieite::cp_ref<T, const xieite::rm_ref<T>>;
}

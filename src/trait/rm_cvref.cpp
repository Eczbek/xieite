export module xieite:rm_cvref;

import :rm_cv;
import :rm_ref;

export namespace xieite {
	template<typename T>
	using rm_cvref = xieite::rm_cv<xieite::rm_ref<T>>;
}

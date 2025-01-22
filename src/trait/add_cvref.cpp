export module xieite:add_cvref;

import :add_cv;
import :add_ref;

export namespace xieite {
	template<typename T, typename U>
	using add_cvref = xieite::add_cv<xieite::add_ref<T, U>>;
}

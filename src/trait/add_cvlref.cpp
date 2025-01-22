export module xieite:add_cvlref;

import :add_cv;
import :add_lref;

export namespace xieite {
	template<typename T>
	using add_cvlref = xieite::add_cv<xieite::add_lref<T>>;
}

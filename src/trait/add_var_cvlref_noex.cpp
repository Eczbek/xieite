export module xieite:add_var_cvlref_noex;

import :add_noex;
import :add_var_cvlref;

export namespace xieite {
	template<typename T>
	using add_var_cvlref_noex = xieite::add_var_cvlref<xieite::add_noex<T>>;
}

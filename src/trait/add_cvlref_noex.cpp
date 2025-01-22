export module xieite:add_cvlref_noex;

import :add_cvlref_referent;
import :add_noex;

export namespace xieite {
	template<typename T>
	using add_cvlref_noex = xieite::add_cvlref_referent<xieite::add_noex<T>>;
}

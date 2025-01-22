export module xieite:add_vrref_noex;

import :add_noex;
import :add_vrref_referent;

export namespace xieite {
	template<typename T>
	using add_vrref_noex = xieite::add_vrref_referent<xieite::add_noex<T>>;
}

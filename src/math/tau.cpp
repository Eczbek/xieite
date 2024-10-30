export module xieite:tau;

import :is_arith;
import :pi;

export namespace xieite {
	template<xieite::is_arith T>
	constexpr T tau = xieite::pi<T> * 2;
}

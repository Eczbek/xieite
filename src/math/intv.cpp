export module xieite:intv;

import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	struct intv {
		T start;
		T end;
	};
}

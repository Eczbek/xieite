export module xieite:interval;

import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	struct interval {
		T start;
		T end;
	};
}

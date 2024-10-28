export module xieite:interval;

import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	struct Interval {
		T start;
		T end;
	};
}

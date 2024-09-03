export module xieite:math.Interval;

import :concepts.Arithmetic;

export namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct Interval {
		Arithmetic start;
		Arithmetic end;
	};
}

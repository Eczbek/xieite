export module xieite:math.DoubleInteger;

import std;

export namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral>
	struct DoubleInteger {
		UnsignedIntegral lower;
		UnsignedIntegral upper;
	};
}

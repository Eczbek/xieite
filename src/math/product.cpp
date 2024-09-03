export module xieite:math.Product;

import std;

export namespace xieite::math {
	template<std::unsigned_integral UnsignedIntegral>
	struct Product {
		UnsignedIntegral lower;
		UnsignedIntegral upper;
	};
}

export module xieite:dbl_uint;

import std;

export namespace xieite {
	template<std::unsigned_integral T>
	struct dbl_uint {
		T lower;
		T upper;
	};
}

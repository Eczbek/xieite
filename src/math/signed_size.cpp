export module xieite:math.SignedSize;

import std;

export namespace xieite::math {
	using SignedSize = std::make_signed_t<std::size_t>;
}

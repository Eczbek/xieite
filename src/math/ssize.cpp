export module xieite:ssize;

import std;

export namespace xieite {
	using ssize = std::make_signed_t<std::size_t>;
}

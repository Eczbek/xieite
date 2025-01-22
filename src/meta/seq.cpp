export module xieite:seq;

import :is_same;

export namespace xieite {
	template<auto... i>
	requires(xieite::is_same<decltype(i)...>)
	struct seq {};
}

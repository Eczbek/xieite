export module xieite:make_seq;

import std;
import :seq;

export namespace xieite {
	template<auto n>
	constexpr decltype(([]<typename T, T... i>(std::integer_sequence<T, i...>) {
		return xieite::seq<i...>();
	})(std::make_integer_sequence<decltype(n), n>())) make_seq;
}

export module xieite:is_pair_like;

import std;
import :arity;
import :is_tuple_like;

export namespace xieite {
	template<typename T>
	concept is_pair_like = xieite::is_tuple_like<T> && (xieite::arity<T> == 2);
}

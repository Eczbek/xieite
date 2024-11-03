export module xieite:vec2;

import :is_arith;

export namespace xieite {
	template<xieite::is_arith T>
	struct vec2 {
		T x;
		T y;
	};

	template<typename T>
	vec2(T, T) -> vec2<T>;
}

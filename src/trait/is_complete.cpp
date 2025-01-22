export module xieite:is_complete;

import :t;

export namespace xieite {
	template<typename T, auto = [] {}>
	concept is_complete = requires { ([]<typename U, auto = sizeof(U)>(xieite::t<U>) {})(xieite::t<T>()); };
}

// TODO: Check for correctness

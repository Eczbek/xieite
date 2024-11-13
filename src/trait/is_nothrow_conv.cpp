export module xieite:is_nothrow_conv;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_nothrow_conv = std::is_nothrow_cast_v<T, U> && requires { static_cast<U>(std::declval<T>()); };
}

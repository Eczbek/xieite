export module xieite:is_nothrow_cast_to;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_nothrow_cast_to = std::is_nothrow_convertible_v<T, U> && requires { static_cast<U>(std::declval<T>()); };
}

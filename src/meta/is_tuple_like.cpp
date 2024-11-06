export module xieite:is_tuple_like;

import std;

export namespace xieite {
	template<typename T>
	concept is_tuple_like = requires { std::tuple_size<T>::value; };
}

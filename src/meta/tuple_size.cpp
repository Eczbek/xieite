export module xieite:tuple_size;

import std;

export namespace xieite {
	template<typename T>
	constexpr std::size_t tuple_size = std::tuple_size_v<std::remove_cvref_t<T>>;
}

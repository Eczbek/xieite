export module xieite:is_streamable_in;

import std;

export namespace xieite {
	template<typename T>
	concept is_streamable_in = requires(T value, std::istream istream) {
		{ istream >> value } -> std::convertible_to<std::istream&>;
	};
}

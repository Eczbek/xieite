export module xieite:is_streamable_in;

import std;

export namespace xieite {
	template<typename T>
	concept is_streamable_in = requires (T x, std::istream istream) {
		{ istream >> x } -> std::convertible_to<std::istream&>;
	};
}

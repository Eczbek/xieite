export module xieite:is_streamable_out;

import std;

export namespace xieite {
	template<typename T>
	concept is_streamable_out = requires (T x, std::ostream ostream) {
		{ ostream << x } -> std::convertible_to<std::ostream&>;
	};
}

// Thanks to fux for original code

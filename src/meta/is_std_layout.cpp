export module xieite:is_std_layout;

import std;

export namespace xieite {
	template<typename T>
	concept is_std_layout = std::is_standard_layout_v<T>;
}

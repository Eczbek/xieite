export module xieite:is_narrow_ch;

import std;
import :is_ordinary_ch;
import :rm_cv;

export namespace xieite {
	template<typename T>
	concept is_narrow_ch = xieite::is_ordinary_ch<T> || std::same_as<xieite::rm_cv<T>, char8_t>;
	// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-3
}

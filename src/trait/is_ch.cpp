export module xieite:is_ch;

import :is_same_any;
import :is_wide_ch;
import :rm_cv;

export namespace xieite {
	template<typename T>
	concept is_ch = xieite::is_wide_ch<T> || xieite::is_same_any<xieite::rm_cv<T>, char, char8_t>;
	// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#11.sentence-1
}

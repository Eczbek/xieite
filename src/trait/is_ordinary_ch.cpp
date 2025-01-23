export module xieite:is_ordinary_ch;

import :is_same_any;
import :rm_cv;

export namespace xieite {
	template<typename T>
	concept is_ordinary_ch = xieite::is_same_any<xieite::rm_cv<T>, char, unsigned char, signed char>;
	// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-2
}

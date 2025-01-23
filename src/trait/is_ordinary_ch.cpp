export module xieite:is_ordinary_ch;

import std;
import :is_same_any;

export namespace xieite {
	template<typename T>
	concept is_ordinary_ch = xieite::is_same_any<std::remove_cv_t<T>, char, signed char, unsigned char>;
	// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-2
}

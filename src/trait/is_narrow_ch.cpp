export module xieite:is_narrow_ch;

import std;
import :is_ordinary_ch;

export namespace xieite {
	template<typename T>
	concept is_narrow_ch = xieite::is_ordinary_ch<T> || std::same_as<std::remove_cv_t<T>, char8_t>;
	// https://timsong-cpp.github.io/cppwp/n4950/basic.fundamental#7.sentence-3
}

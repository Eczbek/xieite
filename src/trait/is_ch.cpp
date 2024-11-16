export module xieite:is_ch;

import std;
import :is_same_any;
import :is_wide_ch;

export namespace xieite {
	template<typename T>
	concept is_ch = xieite::is_wide_ch<T> || xieite::is_same_any<std::remove_cv_t<T>, char, char8_t>;
	// https://eel.is/c++draft/basic.fundamental#11.sentence-1
}

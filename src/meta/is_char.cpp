export module xieite:is_char;

import std;
import :is_same_as_any;
import :is_wide_char;

export namespace xieite {
	template<typename T>
	concept is_char = xieite::is_wide_char<T> || xieite::is_same_as_any<std::remove_cv_t<T>, char, char8_t>;
}

// https://eel.is/c++draft/basic.fundamental#11

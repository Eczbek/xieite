export module xieite:is_ordinary_char;

import std;
import :is_same_as_any;

export namespace xieite {
	template<typename T>
	concept is_ordinary_char = xieite::is_same_as_any<std::remove_cv_t<T>, char, signed char, unsigned char>;
}

// https://eel.is/c++draft/basic.fundamental#7

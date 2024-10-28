export module xieite:is_narrow_char;

import std;
import :is_ordinary_char;

export namespace xieite {
	template<typename T>
	concept is_narrow_char = xieite::is_ordinary_char<T> || std::same_as<std::remove_cv_t<T>, char8_t>;
}

// https://eel.is/c++draft/basic.fundamental#7

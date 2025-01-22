export module xieite:is_wide_ch;

import std;
import :is_same_any;

export namespace xieite {
	template<typename T>
	concept is_wide_ch = xieite::is_same_any<std::remove_cv_t<T>, wchar_t, char16_t, char32_t>;
	// A section from the C++ working draft was previously linked here, but now it's gone and apparently never existed. Oh well.
}

export module xieite:is_wide_ch;

import :is_same_any;
import :rm_cv

export namespace xieite {
	template<typename T>
	concept is_wide_ch = xieite::is_same_any<xieite::rm_cv<T>, wchar_t, char16_t, char32_t>;
	// I'm certain that a section of the C++ working draft was previously referenced here, but now it's gone and apparently never existed. Oh well.
}

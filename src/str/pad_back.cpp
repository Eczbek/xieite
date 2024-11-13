export module xieite:pad_back;

import std;
import :end;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>,
		xieite::end...,
		typename Str = std::basic_string<Ch, Traits, Alloc>>
	[[nodiscard]] constexpr Str pad_back(Str str, std::size_t size, Ch c = ' ') noexcept {
		str.reserve(size);
		if (str.size() < size) {
			return str + Str(size - str.size(), c);
		}
		return str;
	}
}

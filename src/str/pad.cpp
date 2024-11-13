export module xieite:pad;

import std;
import :end;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>,
		xieite::end...,
		typename Str = std::basic_string<Ch, Traits, Alloc>>
	[[nodiscard]] constexpr Str pad(Str str, std::size_t size, Ch c = ' ', bool align_front = true) noexcept {
		str.reserve(size);
		if (str.size() < size) {
			return Str((size - str.size() + !align_front) / 2, c) + str + Str((size - str.size() + align_front) / 2, c);
		}
		return str;
	}
}

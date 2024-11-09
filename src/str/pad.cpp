export module xieite:pad;

import std;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad(std::basic_string<Ch, Traits, Alloc> str, std::size_t size, Ch c = ' ', bool align_front = true) noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		str.reserve(size);
		if (str.size() < size) {
			return Str((size - str.size() + !align_front) / 2, c) + str + Str((size - str.size() + align_front) / 2, c);
		}
		return str;
	}
}

export module xieite:pad_back;

import std;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad_back(std::basic_string<Ch, Traits, Alloc> str, std::size_t size, Ch c = ' ') noexcept {
		str.reserve(size);
		if (str.size() < size) {
			return str + std::basic_string<Ch, Traits, Alloc>(size - str.size(), c);
		}
		return str;
	}
}
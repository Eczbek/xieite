export module xieite:pad_back;

import std;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> pad_back(std::basic_string_view<C, Traits> str, std::size_t size, C c = ' ') noexcept {
		using Str = std::basic_string<C, Traits, Alloc>;
		Str result = Str(str);
		result.reserve(size);
		if (str.size() < size) {
			result += Str(size - str.size(), c);
		}
		return result;
	}
}

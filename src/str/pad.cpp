export module xieite:pad;

import std;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>, typename Alloc = std::allocator<C>>
	[[nodiscard]] constexpr std::basic_string<C, Traits, Alloc> pad(std::basic_string_view<C, Traits> str, std::size_t size, C c = ' ', bool align_front = true) noexcept {
		using Str = std::basic_string<C, Traits, Alloc>;
		Str result = Str(str);
		result.reserve(size);
		if (str.size() < size) {
			return Str((size - str.size() + !align_front) / 2, c) + result + Str((size - str.size() + align_front) / 2, c);
		}
		return result;
	}
}

export module xieite:sv;

import std;
import :is_char;

export namespace xieite {
	template<typename Char = char, typename Traits = std::char_traits<Char>>
	struct sv : std::basic_string_view<Char, Traits> {
		using std::basic_string_view<Char, Traits>::basic_string_view;

		explicit(false) constexpr sv(std::basic_string_view<Char, Traits> str) noexcept
		: std::basic_string_view<Char, Traits>(str) {}

		template<typename Alloc = std::allocator<Char>>
		explicit(false) constexpr sv(const std::basic_string<Char, Traits, Alloc>& str) noexcept
		: std::basic_string_view<Char, Traits>(str) {}

		explicit(false) constexpr sv(const Char& c) noexcept
		: std::basic_string_view<Char, Traits>(&c, 1) {}

		template<typename Alloc = std::allocator<Char>>
		[[nodiscard]] explicit(false) constexpr operator std::basic_string<Char, Traits, Alloc>() const noexcept {
			return std::basic_string<Char, Traits, Alloc>(*this);
		}
	};

	template<typename Char, typename Traits>
	sv(std::basic_string_view<Char, Traits>) -> sv<Char, Traits>;

	template<typename Char, typename Traits, typename Alloc>
	sv(const std::basic_string<Char, Traits, Alloc>&) -> sv<Char, Traits>;

	template<xieite::is_char Char>
	sv(const Char&) -> sv<Char>;
}

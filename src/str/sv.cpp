export module xieite:sv;

import std;
import :is_char;

export namespace xieite {
	template<typename C = char, typename Traits = std::char_traits<C>>
	struct sv : std::basic_string_view<C, Traits> {
		using std::basic_string_view<C, Traits>::basic_string_view;

		explicit(false) constexpr sv(std::basic_string_view<C, Traits> str) noexcept
		: std::basic_string_view<C, Traits>(str) {}

		template<typename Alloc = std::allocator<C>>
		explicit(false) constexpr sv(const std::basic_string<C, Traits, Alloc>& str) noexcept
		: std::basic_string_view<C, Traits>(str) {}

		explicit(false) constexpr sv(const C& c) noexcept
		: std::basic_string_view<C, Traits>(&c, 1) {}

		template<typename Alloc = std::allocator<C>>
		[[nodiscard]] explicit(false) constexpr operator std::basic_string<C, Traits, Alloc>() const noexcept {
			return std::basic_string<C, Traits, Alloc>(*this);
		}
	};

	template<typename C, typename Traits>
	sv(std::basic_string_view<C, Traits>) -> sv<C, Traits>;

	template<typename C, typename Traits, typename Alloc>
	sv(const std::basic_string<C, Traits, Alloc>&) -> sv<C, Traits>;

	template<xieite::is_char C>
	sv(const C&) -> sv<C>;
}

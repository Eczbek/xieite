export module xieite:sv;

import std;
import :is_ch;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	struct sv : std::basic_string_view<Ch, Traits> {
		using std::basic_string_view<Ch, Traits>::basic_string_view;

		explicit(false) constexpr sv(std::basic_string_view<Ch, Traits> str) noexcept
		: std::basic_string_view<Ch, Traits>(str) {}

		template<typename Alloc = std::allocator<Ch>>
		explicit(false) constexpr sv(const std::basic_string<Ch, Traits, Alloc>& str) noexcept
		: std::basic_string_view<Ch, Traits>(str) {}

		explicit(false) constexpr sv(const Ch& c) noexcept
		: std::basic_string_view<Ch, Traits>(&c, 1) {}

		template<typename Alloc = std::allocator<Ch>>
		[[nodiscard]] explicit(false) constexpr operator std::basic_string<Ch, Traits, Alloc>() const noexcept {
			return std::basic_string<Ch, Traits, Alloc>(*this);
		}
	};

	template<typename Ch, typename Traits>
	sv(std::basic_string_view<Ch, Traits>) -> sv<Ch, Traits>;

	template<typename Ch, typename Traits, typename Alloc>
	sv(const std::basic_string<Ch, Traits, Alloc>&) -> sv<Ch, Traits>;

	template<xieite::is_ch Ch>
	sv(const Ch&) -> sv<Ch>;
}

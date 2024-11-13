export module xieite:chv;

import std;
import :is_ch;

export namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>>
	struct chv : std::basic_string_view<Ch, Traits> {
		using std::basic_string_view<Ch, Traits>::basic_string_view;

		explicit(false) constexpr chv(std::basic_string_view<Ch, Traits> str) noexcept
		: std::basic_string_view<Ch, Traits>(str) {}

		template<typename Alloc = std::allocator<Ch>>
		explicit(false) constexpr chv(const std::basic_string<Ch, Traits, Alloc>& str) noexcept
		: std::basic_string_view<Ch, Traits>(str) {}

		explicit(false) constexpr chv(const Ch& c) noexcept
		: std::basic_string_view<Ch, Traits>(&c, 1) {}

		template<typename Alloc = std::allocator<Ch>>
		[[nodiscard]] explicit(false) constexpr operator std::basic_string<Ch, Traits, Alloc>() const noexcept {
			return std::basic_string<Ch, Traits, Alloc>(*this);
		}
	};

	template<typename Ch, typename Traits>
	chv(std::basic_string_view<Ch, Traits>) -> chv<Ch, Traits>;

	template<typename Ch, typename Traits, typename Alloc>
	chv(const std::basic_string<Ch, Traits, Alloc>&) -> chv<Ch, Traits>;

	template<xieite::is_ch Ch>
	chv(const Ch&) -> chv<Ch>;
}

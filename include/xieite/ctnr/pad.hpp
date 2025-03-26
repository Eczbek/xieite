#ifndef DETAIL_XIEITE_HEADER_CTNR_PAD
#	define DETAIL_XIEITE_HEADER_CTNR_PAD
#
#	include <cstddef>
#	include <memory>
#	include <string>
#	include <string_view>
#	include "../meta/group.hpp"
#	include "../pp/arrow.hpp"
#	include "../trait/is_ch.hpp"

namespace xieite {
	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad(const std::basic_string<Ch, Traits, Alloc>& str, std::size_t size, Ch c = ' ', bool align_front = true, Alloc&& alloc = {}) noexcept(false) {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (str.size() < size)
			? Str((size - str.size() + !align_front) / 2, c, alloc) + str + Str((size - str.size() + align_front) / 2, c, alloc)
			: str;
	}

	template<typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto pad(std::basic_string_view<Ch, Traits> strv, std::size_t size, Ch c = ' ', bool align_front = true, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::pad(std::basic_string<Ch, Traits, Alloc>(strv, alloc), size, c, alloc))

	template<xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto pad(const xieite::group<Ch[n]>& str, std::size_t size, Ch c = ' ', bool align_front = true, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::pad(std::basic_string<Ch, Traits, Alloc>(str, n, alloc), size, c, alloc))
}

#endif

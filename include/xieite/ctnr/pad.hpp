#pragma once

#include <cstddef>
#include <memory>
#include <string>

namespace xieite {
	template<typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> pad(std::basic_string_view<Ch, Traits> strv, std::size_t size, Ch c = ' ', bool align_front = true) noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		return (strv.size() < size)
			? Str((size - strv.size() + !align_front) / 2, c) + Str(strv) + Str((size - strv.size() + align_front) / 2, c)
			: Str(strv);
	}
}

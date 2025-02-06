#pragma once

#include <concepts>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <type_traits>
#include "../ctnr/str_view.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_ch.hpp"

namespace xieite {
	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<std::basic_string<Ch, Traits, Alloc>, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, std::basic_string_view<Ch, Traits> delim = "", std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx = "", std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {}) noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return Str("", 0, alloc);
		}
		Str result = Str(*iterator, alloc);
		while (++iterator != end) {
			result += Str(delim, alloc);
			result += Str(*iterator, alloc);
		}
		return Str(pfx, alloc) + result + Str(sfx, alloc);
	}

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_join(R&& range, std::basic_string_view<Ch, Traits> delim, Ch pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), delim, xieite::str_view(pfx), sfx, XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_join(R&& range, std::basic_string_view<Ch, Traits> delim, std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, Ch sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), delim, pfx, xieite::str_view(sfx), XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_join(R&& range, std::basic_string_view<Ch, Traits> delim, Ch pfx, Ch sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), delim, xieite::str_view(pfx), xieite::str_view(sfx), XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_join(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx = "", std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), pfx, sfx, XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_join(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, Ch pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), xieite::str_view(pfx), sfx, XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_join(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, Ch sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), pfx, xieite::str_view(sfx), XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto str_join(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, Ch pfx, Ch sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), xieite::str_view(pfx), xieite::str_view(sfx), XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_join(R&& range, const Ch(& delim)[n], std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Ch, Traits>(delim), pfx, sfx, XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_join(R&& range, const Ch(& delim)[n], Ch pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Ch, Traits>(delim), xieite::str_view(pfx), sfx, XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_join(R&& range, const Ch(& delim)[n], std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, Ch sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Ch, Traits>(delim), pfx, xieite::str_view(sfx), XIEITE_FWD(alloc)))

	template<std::ranges::input_range R, xieite::is_ch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto str_join(R&& range, const Ch(& delim)[n], Ch pfx, Ch sfx, Alloc&& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Ch, Traits>(delim), xieite::str_view(pfx), xieite::str_view(sfx), XIEITE_FWD(alloc)))
}

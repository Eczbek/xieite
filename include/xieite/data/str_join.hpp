#ifndef DETAIL_XIEITE_HEADER_DATA_STR_JOIN
#	define DETAIL_XIEITE_HEADER_DATA_STR_JOIN
#
#	include <concepts>
#	include <memory>
#	include <ranges>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../data/str_view.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	requires(std::constructible_from<std::basic_string<Char, Traits, Alloc>, std::ranges::range_common_reference_t<Range>>)
	[[nodiscard]] constexpr std::basic_string<Char, Traits, Alloc> str_join(Range&& range, std::basic_string_view<Char, Traits> delim = "", std::type_identity_t<std::basic_string_view<Char, Traits>> pfx = "", std::type_identity_t<std::basic_string_view<Char, Traits>> sfx = "", const Alloc& alloc = {}) noexcept {
		using Str = std::basic_string<Char, Traits, Alloc>;
		auto iter = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iter == end) {
			return Str("", 0, alloc);
		}
		Str result = Str(*iter, alloc);
		while (++iter != end) {
			result += Str(delim, alloc);
			result += Str(*iter, alloc);
		}
		return Str(pfx, alloc) + result + Str(sfx, alloc);
	}

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_join(Range&& range, std::basic_string_view<Char, Traits> delim, Char pfx, std::type_identity_t<std::basic_string_view<Char, Traits>> sfx = "", const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), delim, xieite::str_view(pfx), sfx, alloc))

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_join(Range&& range, std::basic_string_view<Char, Traits> delim, std::type_identity_t<std::basic_string_view<Char, Traits>> pfx, Char sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), delim, pfx, xieite::str_view(sfx), alloc))

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_join(Range&& range, std::basic_string_view<Char, Traits> delim, Char pfx, Char sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), delim, xieite::str_view(pfx), xieite::str_view(sfx), alloc))

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_join(Range&& range, const std::basic_string<Char, Traits, Alloc>& delim, std::type_identity_t<std::basic_string_view<Char, Traits>> pfx = "", std::type_identity_t<std::basic_string_view<Char, Traits>> sfx = "", const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), pfx, sfx, alloc))

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_join(Range&& range, const std::basic_string<Char, Traits, Alloc>& delim, Char pfx, std::type_identity_t<std::basic_string_view<Char, Traits>> sfx = "", const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), xieite::str_view(pfx), sfx, alloc))

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_join(Range&& range, const std::basic_string<Char, Traits, Alloc>& delim, std::type_identity_t<std::basic_string_view<Char, Traits>> pfx, Char sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), pfx, xieite::str_view(sfx), alloc))

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>>
	[[nodiscard]] constexpr auto str_join(Range&& range, const std::basic_string<Char, Traits, Alloc>& delim, Char pfx, Char sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view(delim), xieite::str_view(pfx), xieite::str_view(sfx), alloc))

	template<std::ranges::input_range Range, typename Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_join(Range&& range, const xieite::paren<Char[length]>& delim, std::type_identity_t<std::basic_string_view<Char, Traits>> pfx, std::type_identity_t<std::basic_string_view<Char, Traits>> sfx = "", const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Char, Traits>(delim), pfx, sfx, alloc))

	template<std::ranges::input_range Range, xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_join(Range&& range, const xieite::paren<Char[length]>& delim, Char pfx, std::type_identity_t<std::basic_string_view<Char, Traits>> sfx = "", const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Char, Traits>(delim), xieite::str_view(pfx), sfx, alloc))

	template<std::ranges::input_range Range, xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_join(Range&& range, const xieite::paren<Char[length]>& delim, std::type_identity_t<std::basic_string_view<Char, Traits>> pfx, Char sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Char, Traits>(delim), pfx, xieite::str_view(sfx), alloc))

	template<std::ranges::input_range Range, xieite::is_char Char, typename Traits = std::char_traits<Char>, typename Alloc = std::allocator<Char>, std::size_t length>
	[[nodiscard]] constexpr auto str_join(Range&& range, const xieite::paren<Char[length]>& delim, Char pfx, Char sfx, const Alloc& alloc = {})
		XIEITE_ARROW(xieite::str_join(XIEITE_FWD(range), xieite::str_view<Char, Traits>(delim), xieite::str_view(pfx), xieite::str_view(sfx), alloc))
}

#endif

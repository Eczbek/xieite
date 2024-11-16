module;

#include <xieite/fwd.hpp>

export module xieite:str_join;

import std;

export namespace xieite {
	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, std::basic_string_view<Ch, Traits> delim = "", std::basic_string_view<Ch, Traits> pfx = "", std::basic_string_view<Ch, Traits> sfx = "") noexcept {
		using Str = std::basic_string<Ch, Traits, Alloc>;
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		if (iterator == end) {
			return "";
		}
		Str result = Str(*iterator);
		while (++iterator != end) {
			result += Str(delim);
			result += Str(*iterator);
		}
		return Str(pfx) + result + Str(sfx);
	}

	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, Ch delim, std::basic_string_view<Ch, Traits> pfx = "", std::basic_string_view<Ch, Traits> sfx = "") noexcept {
		return xieite::str_join(XIEITE_FWD(range), std::basic_string_view<Ch, Traits>(&delim, 1), pfx, sfx);
	}

	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, std::basic_string_view<Ch, Traits> delim, Ch pfx, std::basic_string_view<Ch, Traits> sfx = "") noexcept {
		return xieite::str_join(XIEITE_FWD(range), delim, std::basic_string_view<Ch, Traits>(&pfx, 1), sfx);
	}

	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, Ch delim, Ch pfx, std::basic_string_view<Ch, Traits> sfx = "") noexcept {
		return xieite::str_join(XIEITE_FWD(range), std::basic_string_view<Ch, Traits>(&delim, 1), std::basic_string_view<Ch, Traits>(&pfx, 1), sfx);
	}

	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, Ch delim, std::basic_string_view<Ch, Traits> pfx, Ch sfx) noexcept {
		return xieite::str_join(XIEITE_FWD(range), std::basic_string_view<Ch, Traits>(&delim, 1), pfx, std::basic_string_view<Ch, Traits>(&sfx, 1));
	}

	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, std::basic_string_view<Ch, Traits> delim, Ch pfx, Ch sfx) noexcept {
		return xieite::str_join(XIEITE_FWD(range), delim, std::basic_string_view<Ch, Traits>(&pfx, 1), std::basic_string_view<Ch, Traits>(&sfx, 1));
	}

	template<std::ranges::input_range R, typename Ch = char, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<Str, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> str_join(R&& range, Ch delim, Ch pfx, std::basic_string_view<Ch, Traits> sfx = "") noexcept {
		return xieite::str_join(XIEITE_FWD(range), std::basic_string_view<Ch, Traits>(&delim, 1), std::basic_string_view<Ch, Traits>(&pfx, 1), std::basic_string_view<Ch, Traits>(&sfx, 1));
	}
}

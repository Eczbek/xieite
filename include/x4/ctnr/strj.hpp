#pragma once

#include <concepts>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <type_traits>
#include "../ctnr/strv.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"

namespace x4 {
	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	requires(std::constructible_from<std::basic_string<Ch, Traits, Alloc>, std::ranges::range_common_reference_t<R>>)
	[[nodiscard]] constexpr std::basic_string<Ch, Traits, Alloc> strj(R&& range, std::basic_string_view<Ch, Traits> delim = "", std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx = "", std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {}) noexcept {
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
	[[nodiscard]] constexpr auto strj(R&& range, std::basic_string_view<Ch, Traits> delim, Ch pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), delim, x4::strv(pfx), sfx, X4FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strj(R&& range, std::basic_string_view<Ch, Traits> delim, std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, Ch sfx, Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), delim, pfx, x4::strv(sfx), X4FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strj(R&& range, std::basic_string_view<Ch, Traits> delim, Ch pfx, Ch sfx, Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), delim, x4::strv(pfx), x4::strv(sfx), X4FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strj(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx = "", std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv(delim), pfx, sfx, X4FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strj(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, Ch pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv(delim), x4::strv(pfx), sfx, X4FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strj(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, Ch sfx, Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv(delim), pfx, x4::strv(sfx), X4FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>>
	[[nodiscard]] constexpr auto strj(R&& range, const std::basic_string<Ch, Traits, Alloc>& delim, Ch pfx, Ch sfx, Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv(delim), x4::strv(pfx), x4::strv(sfx), X4FWD(alloc)))

	template<std::ranges::input_range R, typename Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strj(R&& range, const Ch(& delim)[n], std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv<Ch, Traits>(delim), pfx, sfx, X4FWD(alloc)))

	template<std::ranges::input_range R, x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strj(R&& range, const Ch(& delim)[n], Ch pfx, std::type_identity_t<std::basic_string_view<Ch, Traits>> sfx = "", Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv<Ch, Traits>(delim), x4::strv(pfx), sfx, X4FWD(alloc)))

	template<std::ranges::input_range R, x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strj(R&& range, const Ch(& delim)[n], std::type_identity_t<std::basic_string_view<Ch, Traits>> pfx, Ch sfx, Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv<Ch, Traits>(delim), pfx, x4::strv(sfx), X4FWD(alloc)))

	template<std::ranges::input_range R, x4::isch Ch, typename Traits = std::char_traits<Ch>, typename Alloc = std::allocator<Ch>, std::size_t n>
	[[nodiscard]] constexpr auto strj(R&& range, const Ch(& delim)[n], Ch pfx, Ch sfx, Alloc&& alloc = {})
		X4AR(x4::strj(X4FWD(range), x4::strv<Ch, Traits>(delim), x4::strv(pfx), x4::strv(sfx), X4FWD(alloc)))
}

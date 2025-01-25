#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <ranges>
#include <string>
#include <string_view>
#include "../ctnr/make_array.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::size_t size_, typename Ch = char>
	struct fixed_str {
		using value_type = Ch;

		static constexpr std::size_t size = size_;
		std::array<Ch, size_> data;

		[[nodiscard]] explicit(false) constexpr fixed_str(const Ch(&data)[size_]) noexcept {
			std::ranges::copy_n(data, size_, this->data.begin());
		}

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, Ch>)
		[[nodiscard]] explicit(false) constexpr fixed_str(R&& data)
		noexcept(xieite::is_noex_range<R>)
		: data(xieite::make_array<Ch, size_>(XIEITE_FWD(data))) {}

		template<typename Traits = std::char_traits<Ch>>
		[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> view() const noexcept {
			return std::basic_string_view<Ch, Traits>(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t size, typename Ch>
	fixed_str(const Ch(&)[size]) -> fixed_str<size, Ch>;
}

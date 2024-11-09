module;

#include <xieite/fwd.hpp>

export module xieite:fixed_str;

import std;
import :is_nothrow_range;
import :make_array;

export namespace xieite {
	template<std::size_t chars, typename Ch = char>
	struct fixed_str {
		using value_type = Ch;

		static constexpr std::size_t size = chars;
		std::array<Ch, chars> data;

		constexpr fixed_str(const Ch(&data)[chars]) noexcept {
			std::ranges::copy(data, this->data.begin());
		}

		template<std::ranges::input_range R>
		requires(std::same_as<std::ranges::range_value_t<R>, Ch>)
		constexpr fixed_str(R&& data)
		noexcept(xieite::is_nothrow_range<R>)
		: data(xieite::make_array<Ch, chars>(XIEITE_FWD(data))) {}

		template<typename Traits = std::char_traits<Ch>>
		[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> view() const noexcept {
			return std::basic_string_view<Ch, Traits>(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t chars, typename Ch>
	fixed_str(const Ch(&)[chars]) -> fixed_str<chars, Ch>;
}

module;

#include <xieite/fwd.hpp>

export module xieite:fixed_str;

import std;
import :is_nothrow_range;
import :make_array;

export namespace xieite {
	template<std::size_t size_, typename Ch = char>
	struct fixed_str {
		using value_type = Ch;

		static constexpr std::size_t size = size_;
		std::array<Ch, size_> data;

		[[nodiscard]] constexpr fixed_str(const Ch(&data)[size_]) noexcept {
			std::ranges::copy_n(data, size_, this->data.begin());
		}

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, Ch>)
		[[nodiscard]] constexpr fixed_str(R&& data)
		noexcept(xieite::is_nothrow_range<R>)
		: data(xieite::make_array<Ch, size_>(XIEITE_FWD(data))) {}

		template<typename Traits = std::char_traits<Ch>>
		[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> view() const noexcept {
			return std::basic_string_view<Ch, Traits>(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t size, typename Ch>
	fixed_str(const Ch(&)[size]) -> fixed_str<size, Ch>;
}

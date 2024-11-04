module;

#include <xieite/fwd.hpp>

export module xieite:fixed_str;

import std;
import :is_nothrow_range;
import :make_array;

export namespace xieite {
	template<std::size_t chars, typename C = char>
	struct fixed_str {
		using value_type = C;

		static constexpr std::size_t size = chars;
		std::array<C, chars> data;

		constexpr fixed_str(const C(&data)[chars]) noexcept {
			std::ranges::copy(data, this->data.begin());
		}

		template<std::ranges::input_range R>
		requires(std::same_as<std::ranges::range_value_t<R>, C>)
		constexpr fixed_str(R&& data)
		noexcept(xieite::is_nothrow_range<R>)
		: data(xieite::make_array<C, chars>(XIEITE_FWD(data))) {}

		template<typename Traits = std::char_traits<C>>
		[[nodiscard]] constexpr std::basic_string_view<C, Traits> view() const noexcept {
			return std::basic_string_view<C, Traits>(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t chars, typename C>
	fixed_str(const C(&)[chars]) -> fixed_str<chars, C>;
}

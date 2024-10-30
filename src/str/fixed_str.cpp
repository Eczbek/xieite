module;

#include <xieite/fwd.hpp>

export module xieite:fixed_str;

import std;
import :is_nothrow_range;
import :make_array;

export namespace xieite {
	template<std::size_t chars, typename Char = char>
	struct fixed_str {
		static constexpr std::size_t size = chars;
		std::array<Char, chars> data;

		constexpr fixed_str(const Char(&data)[chars]) noexcept {
			std::ranges::copy(data, this->data.begin());
		}

		template<std::ranges::input_range R>
		requires(std::same_as<std::ranges::range_value_t<R>, Char>)
		constexpr fixed_str(R&& data)
		noexcept(xieite::is_nothrow_range<R>)
		: data(xieite::make_array<Char, chars>(XIEITE_FWD(data))) {}

		[[nodiscard]] constexpr std::string_view view() const noexcept {
			return std::string_view(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t chars, typename Char>
	fixed_str(const Char(&)[chars]) -> fixed_str<chars, Char>;
}

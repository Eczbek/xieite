#ifndef DETAIL_XIEITE_HEADER_DATA_FIXED_STR
#	define DETAIL_XIEITE_HEADER_DATA_FIXED_STR
#
#	include <concepts>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <string>
#	include <string_view>
#	include "../data/fixed_array.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::size_t length, xieite::is_char Char = char>
	struct fixed_str {
		using value_type = Char;
		using reference = Char&;
		using const_reference = const Char&;
		using pointer = Char*;
		using const_pointer = const Char*;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator = Char*;
		using const_iterator = const Char*;
		using reverse_iterator = std::reverse_iterator<Char*>;
		using const_reverse_iterator = std::reverse_iterator<const Char*>;

		xieite::fixed_array<Char, length> array;

		[[nodiscard]] explicit(false) constexpr fixed_str(const xieite::paren<Char[length + 1]>& array) noexcept {
			for (std::size_t i = 0; i < length; ++i) {
				this->array[i] = array[i];
			}
		}

		template<std::ranges::input_range Range>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, Char>)
		[[nodiscard]] explicit(false) constexpr fixed_str(Range&& array)
		noexcept(xieite::is_noex_range<Range>)
		: array(xieite::fixed_array<Char, length>::from(XIEITE_FWD(array))) {}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, std::size_t idx) noexcept {
			return XIEITE_FWD(self).array[idx];
		}

		template<std::size_t other_length>
		[[nodiscard]] friend constexpr auto operator+(const xieite::fixed_str<length, Char>& lhs, const xieite::fixed_str<other_length, Char>& rhs) noexcept {
			return xieite::fixed_str<(length + other_length), Char>(lhs.array + rhs.array);
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return length;
		}

		template<typename Traits = std::char_traits<Char>>
		[[nodiscard]] constexpr std::basic_string_view<Char, Traits> view() const noexcept {
			return std::basic_string_view<Char, Traits>(this->array.begin(), this->array.end());
		}
	};

	template<std::size_t length, typename Char>
	fixed_str(const xieite::paren<Char[length]>&) -> fixed_str<(length - 1), Char>;
}

#endif

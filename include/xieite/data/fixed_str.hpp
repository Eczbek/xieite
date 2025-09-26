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
#	include "../meta/make_seq.hpp"
#	include "../meta/seq.hpp"
#	include "../meta/type.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_char.hpp"

namespace xieite {
	template<xieite::is_char Char, std::size_t length>
	struct fixed_str {
	public:
		using value_type             = Char;
		using reference              = Char&;
		using const_reference        = const Char&;
		using pointer                = Char*;
		using const_pointer          = const Char*;
		using size_type              = std::size_t;
		using difference_type        = std::ptrdiff_t;
		using iterator               = Char*;
		using const_iterator         = const Char*;
		using reverse_iterator       = std::reverse_iterator<Char*>;
		using const_reverse_iterator = std::reverse_iterator<const Char*>;

		xieite::fixed_array<Char, length> array;

		[[nodiscard]] explicit(false) constexpr fixed_str(
			const xieite::type<Char[length + 1]>& array
		) XIEITE_ARROW_CTOR(
			/* empty */, (fixed_str), ((array, xieite::make_seq<length>))
		)

		template<std::ranges::input_range Range>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, Char>)
		[[nodiscard]] explicit(false) constexpr fixed_str(
			Range&& array
		) XIEITE_ARROW_CTOR(
			/* empty */,
			(fixed_str),
			((std::ranges::begin(array), xieite::make_seq<length>))
		)

		[[nodiscard]] constexpr auto&& operator[](
			this auto&& self,
			std::size_t idx
		) noexcept {
			return XIEITE_FWD(self).array[idx];
		}

		template<std::size_t other_length>
		[[nodiscard]] friend constexpr auto operator+(
			const xieite::fixed_str<Char, length>& lhs,
			const xieite::fixed_str<Char, other_length>& rhs
		) noexcept {
			return xieite::fixed_str<Char, (length + other_length)>(
				lhs.array + rhs.array
			);
		}

		static constexpr auto size = xieite::wrap_value<length>();

		template<typename Traits = std::char_traits<Char>>
		[[nodiscard]] constexpr std::basic_string_view<Char, Traits>
		view() const noexcept {
			return std::basic_string_view<Char, Traits>(
				this->array.begin(),
				this->array.end()
			);
		}

	private:
		template<std::size_t... i>
		[[nodiscard]] constexpr fixed_str(
			auto iter,
			xieite::seq<i...>
		) XIEITE_ARROW_CTOR(
			/* empty */,
			array,
			({([]<std::size_t j>(auto& iter) XIEITE_ARROW_IF(
				j, ++iter, *iter
			)).template operator()<i>(iter)...})
		)
	};

	template<typename Char, std::size_t length>
	fixed_str(const xieite::type<Char[length]>&)
		-> fixed_str<Char, (length - 1)>;
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=120041

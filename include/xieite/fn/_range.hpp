#ifndef DETAIL_XIEITE_HEADER_FN_RANGE
#	define DETAIL_XIEITE_HEADER_FN_RANGE
#
#	include <array>
#	include <cstddef>
#	include <string_view>
#	include <type_traits>
#	include "../math/closest.hpp"
#	include "../math/neg.hpp"
#	include "../math/parse_num.hpp"
#	include "../math/ssize_t.hpp"

namespace DETAIL_XIEITE::_range {
	template<auto one_past, decltype(one_past) step>
	struct iter {
		decltype(one_past) value;

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend bool operator==(const DETAIL_XIEITE::_range::iter<one_past, step>&, const DETAIL_XIEITE::_range::iter<one_past, step>&) = default;

		constexpr auto& operator++() noexcept {
			this->value = xieite::closest(this->value, one_past, step + this->value);
			return *this;
		}
	};

	template<auto first, decltype(first) last, decltype(first) step>
	struct range {
		[[nodiscard]] constexpr auto operator-() const noexcept {
			using Type = std::conditional_t<(xieite::neg(last) || std::is_unsigned_v<decltype(first)>), xieite::ssize_t, std::size_t>;
			return DETAIL_XIEITE::_range::range<-static_cast<Type>(first), static_cast<Type>(last), static_cast<Type>(step)>();
		}

		[[nodiscard]] constexpr auto begin() const noexcept {
			return DETAIL_XIEITE::_range::iter<(last + ((first <= last) * 2 - 1)), (step * ((first <= last) * 2 - 1))>(first);
		}

		[[nodiscard]] constexpr auto end() const noexcept {
			static constexpr auto one_past = (last + ((first <= last) * 2 - 1));
			return DETAIL_XIEITE::_range::iter<one_past, step>(one_past);
		}
	};
}

namespace xieite::_range {
	template<char... digits>
	[[nodiscard]] constexpr auto operator""_range() noexcept {
		static constexpr std::array data { digits... };
		static constexpr auto str = std::string_view(data.begin(), data.end());
		static constexpr std::size_t end_delim = str.find('.');
		static constexpr bool has_end = end_delim != std::string_view::npos;
		static constexpr bool end_sign = has_end && (end_delim < (sizeof...(digits) - 1)) && (digits...[end_delim + 1] == '0');
		static constexpr std::size_t step_delim = str.find('e');
		using Type = std::conditional_t<end_sign, xieite::ssize_t, std::size_t>;
		return DETAIL_XIEITE::_range::range<
			xieite::parse_num<Type>(str),
			(has_end ? (xieite::parse_num<Type>(str.substr(end_delim)) * (1 - end_sign * 2)) : 0),
			((step_delim != std::string_view::npos) ? xieite::parse_num<Type>(str.substr(step_delim + (str[step_delim + 1] == '-'))) : 1)
		>();
	}
}

#endif

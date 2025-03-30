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
	template<auto one_past>
	struct iter {
		decltype(one_past) i;
		const decltype(one_past) step = 0;

		[[nodiscard]] constexpr auto operator*() const noexcept {
			return this->i;
		}

		[[nodiscard]] friend constexpr bool operator==(DETAIL_XIEITE::_range::iter<one_past> l, DETAIL_XIEITE::_range::iter<one_past> r) noexcept {
			return l.i == r.i;
		}

		constexpr auto& operator++() noexcept {
			this->i = xieite::closest(this->i, one_past, this->i + this->step);
			return *this;
		}
	};

	template<auto first, decltype(first) last>
	struct range {
		const decltype(first) step = 1;

		[[nodiscard]] constexpr auto operator-() const noexcept {
			using type = std::conditional_t<(xieite::neg(last) || std::is_unsigned_v<decltype(first)>), xieite::ssize_t, std::size_t>;
			return DETAIL_XIEITE::_range::range<-static_cast<type>(first), static_cast<type>(last)>(static_cast<type>(this->step));
		}

		[[nodiscard]] friend constexpr auto operator*(DETAIL_XIEITE::_range::range<first, last>, decltype(first) step) noexcept {
			return DETAIL_XIEITE::_range::range<first, last>(step);
		}

		[[nodiscard]] constexpr auto begin() const noexcept {
			return DETAIL_XIEITE::_range::iter<(last + ((first <= last) * 2 - 1))>(first, this->step * ((first <= last) * 2 - 1));
		}

		[[nodiscard]] constexpr auto end() const noexcept {
			static constexpr auto one_past = (last + ((first <= last) * 2 - 1));
			return DETAIL_XIEITE::_range::iter<one_past>(one_past);
		}
	};
}

namespace xieite::_range {
	template<char... digits>
	[[nodiscard]] constexpr auto operator""_range() noexcept {
		static constexpr std::array data { digits... };
		static constexpr auto str = std::string_view(data.begin(), data.end());
		static constexpr std::size_t delim = str.find('.');
		static constexpr bool has_last = delim != std::string_view::npos;
		static constexpr bool last_sign = has_last && (delim < (sizeof...(digits) - 1)) && (digits...[delim + 1] == '0');
		using type = std::conditional_t<last_sign, xieite::ssize_t, std::size_t>;
		return DETAIL_XIEITE::_range::range<
			xieite::parse_num<type>(str),
			(has_last ? (xieite::parse_num<type>(str.substr(delim)) * (1 - last_sign * 2)) : 0)
		>();
	}
}

#endif

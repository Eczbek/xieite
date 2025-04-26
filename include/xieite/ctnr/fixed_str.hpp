#ifndef DETAIL_XIEITE_HEADER_CTNR_FIXED_STR
#	define DETAIL_XIEITE_HEADER_CTNR_FIXED_STR
#
#	include <concepts>
#	include <cstddef>
#	include <ranges>
#	include <string>
#	include <string_view>
#	include "../ctnr/fixed_array.hpp"
#	include "../meta/paren.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ch.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::size_t n, xieite::is_ch Ch = char>
	struct fixed_str {
		using value_type = Ch;

		xieite::fixed_array<Ch, n> data;

		[[nodiscard]] explicit(false) constexpr fixed_str(const xieite::paren<Ch[n + 1]>& data) noexcept {
			for (std::size_t i = 0; i < n; ++i) {
				this->data[i] = data[i];
			}
		}

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, Ch>)
		[[nodiscard]] explicit(false) constexpr fixed_str(R&& data)
		noexcept(xieite::is_noex_range<R>)
		: data(xieite::fixed_array<Ch, n>::from(XIEITE_FWD(data))) {}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, std::size_t idx) noexcept {
			return XIEITE_FWD(self).data[idx];
		}

		template<std::size_t m>
		[[nodiscard]] friend constexpr auto operator+(const xieite::fixed_str<n, Ch>& l, const xieite::fixed_str<m, Ch>& r) noexcept {
			return xieite::fixed_str<(n + m), Ch>(l.data + r.data);
		}

		[[nodiscard]] static constexpr std::size_t size() noexcept {
			return n;
		}

		template<typename Traits = std::char_traits<Ch>>
		[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> view() const noexcept {
			return std::basic_string_view<Ch, Traits>(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t n, typename Ch>
	fixed_str(const xieite::paren<Ch[n]>&) -> fixed_str<(n - 1), Ch>;
}

#endif

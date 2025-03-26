#ifndef DETAIL_XIEITE_HEADER_CTNR_FIXED_STR
#	define DETAIL_XIEITE_HEADER_CTNR_FIXED_STR
#
#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <ranges>
#	include <string>
#	include <string_view>
#	include "../ctnr/make_array.hpp"
#	include "../meta/group.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_ch.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<std::size_t n, xieite::is_ch Ch = char>
	struct fixed_str {
		using value_type = Ch;

		static constexpr std::size_t size = n;
		std::array<Ch, n> data;

		[[nodiscard]] explicit(false) constexpr fixed_str(const xieite::group<Ch[n + 1]>& data) noexcept {
			for (std::size_t i = 0; i < n; ++i) {
				this->data[i] = data[i];
			}
		}

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, Ch>)
		[[nodiscard]] explicit(false) constexpr fixed_str(R&& data)
		noexcept(xieite::is_noex_range<R>)
		: data(xieite::make_array<Ch, n>(XIEITE_FWD(data))) {}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, std::size_t idx) noexcept {
			return XIEITE_FWD(self).data[idx];
		}

		template<typename Traits = std::char_traits<Ch>>
		[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> view() const noexcept {
			return std::basic_string_view<Ch, Traits>(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t n, typename Ch>
	fixed_str(const xieite::group<Ch[n]>&) -> fixed_str<(n - 1), Ch>;
}

#endif

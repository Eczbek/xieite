#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <ranges>
#include <string>
#include <string_view>
#include "../ctnr/mkarr.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isch.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::size_t n, x4::isch Ch = char>
	struct fstr {
		using value_type = Ch;

		static constexpr std::size_t size = n;
		std::array<Ch, n> data;

		[[nodiscard]] explicit(false) constexpr fstr(const Ch(& data)[n + 1]) noexcept {
			for (std::size_t i = 0; i < n; ++i) {
				this->data[i] = data[i];
			}
		}

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, Ch>)
		[[nodiscard]] explicit(false) constexpr fstr(R&& data)
		noexcept(x4::isnoexrange<R>)
		: data(x4::mkarr<Ch, n>(X4FWD(data))) {}

		template<typename Traits = std::char_traits<Ch>>
		[[nodiscard]] constexpr std::basic_string_view<Ch, Traits> view() const noexcept {
			return std::basic_string_view<Ch, Traits>(this->data.begin(), this->data.end());
		}
	};

	template<std::size_t n, typename Ch>
	fstr(const Ch(&)[n]) -> fstr<(n - 1), Ch>;
}

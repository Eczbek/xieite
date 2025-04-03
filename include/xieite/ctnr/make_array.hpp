#ifndef DETAIL_XIEITE_HEADER_CTNR_MAKE_ARRAY
#	define DETAIL_XIEITE_HEADER_CTNR_MAKE_ARRAY
#
#	include <array>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <ranges>
#	include <utility>
#	include "../fn/unroll.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<typename T, std::size_t n, std::ranges::input_range R = std::initializer_list<T>, xieite::is_invoc<T(std::ranges::range_common_reference_t<R>)> F = std::identity>
	[[nodiscard]] constexpr std::array<T, n> make_array(R&& range, F&& conv = {})
	noexcept(xieite::is_noex_invoc<F, T(std::ranges::range_common_reference_t<R>)>) {
		return xieite::unroll<n>([&range, &conv]<std::size_t... i> -> std::array<T, n> {
			auto iter = std::ranges::begin(range);
			return std::array<T, n> {
				([&conv, &iter] -> decltype(auto) {
					if constexpr (i > 0) {
						++iter;
					}
					return std::invoke(conv, std::forward_like<R>(*iter));
				})()...
			};
		});
	}
}

#endif

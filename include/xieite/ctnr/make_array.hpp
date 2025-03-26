#ifndef DETAIL_XIEITE_HEADER_CTNR_MAKE_ARRAY
#	define DETAIL_XIEITE_HEADER_CTNR_MAKE_ARRAY
#
#	include <array>
#	include <cstddef>
#	include <functional>
#	include <initializer_list>
#	include <ranges>
#	include <utility>
#	include "../fn/cast.hpp"
#	include "../fn/unroll.hpp"
#	include "../trait/is_invoc.hpp"
#	include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<typename V, std::size_t size, std::ranges::input_range R = std::initializer_list<V>, xieite::is_invoc<V(std::ranges::range_common_reference_t<R>)> F = decltype(xieite::cast<V>)>
	[[nodiscard]] constexpr std::array<V, size> make_array(R&& range, F&& conv = {})
	noexcept(xieite::is_noex_invoc<F, V(std::ranges::range_common_reference_t<R>)>) {
		return xieite::unroll<size>([&range, &conv]<std::size_t... i> -> std::array<V, size> {
			auto iter = std::ranges::begin(range);
			return std::array<V, size> {
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

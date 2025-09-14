#ifndef DETAIL_XIEITE_HEADER_DATA_MAKE_ARRAY
#	define DETAIL_XIEITE_HEADER_DATA_MAKE_ARRAY
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
	template<typename Value, std::size_t length, std::ranges::input_range Range = std::initializer_list<Value>, xieite::is_invoc<Value(std::ranges::range_common_reference_t<Range>)> Conv = std::identity>
	[[nodiscard]] constexpr std::array<Value, length> make_array(Range&& range, Conv&& conv = {})
	noexcept(xieite::is_noex_invoc<Conv, Value(std::ranges::range_common_reference_t<Range>)>) {
		return xieite::unroll<length>([&range, &conv]<std::size_t... i> -> std::array<Value, length> {
			auto iter = std::ranges::begin(range);
			return std::array<Value, length> {
				([&conv, &iter] -> decltype(auto) {
					if constexpr (i > 0) {
						++iter;
					}
					return std::invoke(conv, std::forward_like<Range>(*iter));
				})()...
			};
		});
	}
}

#endif

#ifndef XIEITE_HEADER_CONTAINERS_MAKE_ARRAY
#	define XIEITE_HEADER_CONTAINERS_MAKE_ARRAY

#	include <cstddef>
#	include <concepts>
#	include <iterator>
#	include <ranges>
#	include <utility>

namespace xieite::containers {
	template<typename Value, std::size_t size, std::ranges::range Range>
	requires(std::convertible_to<Value, std::ranges::range_value_t<Range>>)
	[[nodiscard]] constexpr std::array<Value, size> makeArray(const Range& range) noexcept {
		return std::array<Value, size>(([&range]<std::size_t... indices>(std::index_sequence<indices...>) {
			return std::array<Value, size> {
				static_cast<Value>(*std::ranges::next(std::ranges::begin(range), indices, std::ranges::end(range)))...
			};
		})(std::make_index_sequence<size>()));
	}
}

#endif

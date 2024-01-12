#ifndef XIEITE_HEADER_CONTAINERS_MAKE_ARRAY
#	define XIEITE_HEADER_CONTAINERS_MAKE_ARRAY

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include <utility>
#	include "../concepts/no_throw_convertible_to.hpp"

namespace xieite::containers {
	template<typename Value, std::size_t size, std::ranges::range Range>
	requires(std::convertible_to<std::ranges::range_reference_t<Range>, Value>)
	[[nodiscard]] constexpr std::array<Value, size> makeArray(const Range& range)
	noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_reference_t<Range>, Value>) {
		return ([&range]<std::size_t... indices>(std::index_sequence<indices...>) {
			return std::array<Value, size> {
				static_cast<Value>(*std::ranges::next(std::ranges::begin(range), indices, std::ranges::end(range)))...
			};
		})(std::make_index_sequence<size>());
	}

	template<typename... Arguments, typename Value = std::common_type_t<Arguments...>, std::size_t size = sizeof...(Arguments)>
	requires(sizeof...(Arguments) <= size)
	[[nodiscard]] constexpr std::array<Value, size> makeArray(const Arguments&... values) noexcept {
		return std::array<Value, size> {
			static_cast<Value>(values)...
		};
	}
}

#endif

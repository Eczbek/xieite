#ifndef XIEITE_HEADER_CONTAINERS_MAKE_ARRAY
#	define XIEITE_HEADER_CONTAINERS_MAKE_ARRAY

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include <utility>
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../concepts/range_of.hpp"

namespace xieite::containers {
	template<typename Value, std::size_t size, xieite::concepts::RangeOf<Value> Range, xieite::concepts::Functable<Value(std::ranges::range_reference_t<Range>)> Functor = decltype([](const std::ranges::range_const_reference_t<Range> value) -> Value {
		return static_cast<Value>(value);
	})>
	[[nodiscard]] constexpr std::array<Value, size> makeArray(const Range& range, Functor&& converter = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_const_reference_t<Range>>) {
		return ([&range, &converter]<std::size_t... indices>(std::index_sequence<indices...>) {
			return std::array<Value, size> {
				std::invoke(converter, *std::ranges::next(std::ranges::begin(range), indices, std::ranges::end(range)))...
			};
		})(std::make_index_sequence<size>());
	}
}

#endif

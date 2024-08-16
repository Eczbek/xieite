#ifndef XIEITE_HEADER_CONTAINERS_MAKE_ARRAY
#	define XIEITE_HEADER_CONTAINERS_MAKE_ARRAY

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include <utility>
#	include "../concepts/functor.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../functors/static_cast.hpp"

namespace xieite::containers {
	template<typename Value, std::size_t size, std::ranges::input_range Range, xieite::concepts::Functor<Value(std::ranges::range_reference_t<Range>)> Functor = xieite::functors::StaticCast<Value>>
	requires(std::convertible_to<std::ranges::range_value_t<Range>, Value>)
	[[nodiscard]] constexpr std::array<Value, size> makeArray(Range&& range, Functor&& converter = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_const_reference_t<Range>>) {
		return ([&range, &converter]<std::size_t... i>(std::index_sequence<i...>) -> std::array<Value, size> {
			auto iterator = std::ranges::begin(range);
			return std::array<Value, size> {
				(void(i), std::invoke(converter, *iterator++))...
			};
		})(std::make_index_sequence<size>());
	}
}

#endif

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
#	include "../functors/static_cast.hpp"

namespace xieite::containers {
	template<typename Value, std::size_t size, xieite::concepts::RangeOf<Value> Range, xieite::concepts::Functable<Value(std::ranges::range_reference_t<Range>)> Functor = xieite::functors::StaticCast<Value>>
	[[nodiscard]] constexpr std::array<Value, size> makeArray(Range&& range, Functor&& converter = Functor())
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_const_reference_t<Range>>) {
		return ([&range, &converter]<std::size_t... i>(std::index_sequence<i...>) {
			return std::array<Value, size> {
				std::invoke(converter, *std::ranges::next(std::ranges::begin(range), i, std::ranges::end(range)))...
			};
		})(std::make_index_sequence<size>());
	}
}

#endif

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
	template<typename Value_, std::size_t size_, xieite::concepts::RangeOf<Value_> Range_, xieite::concepts::Functable<Value_(std::ranges::range_reference_t<Range_>)> Functor_ = xieite::functors::StaticCast<Value_>>
	[[nodiscard]] constexpr std::array<Value_, size_> makeArray(Range_&& range, Functor_&& converter = Functor_())
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_const_reference_t<Range_>>) {
		return ([&range, &converter]<std::size_t... i_>(std::index_sequence<i_...>) {
			return std::array<Value_, size_> {
				std::invoke(converter, *std::ranges::next(std::ranges::begin(range), i_, std::ranges::end(range)))...
			};
		})(std::make_index_sequence<size_>());
	}
}

#endif

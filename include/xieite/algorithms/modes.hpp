#ifndef XIEITE_HEADER_ALGORITHMS_MODES
#	define XIEITE_HEADER_ALGORITHMS_MODES

#	include <cstddef>
#	include <functional>
#	include <iterator>
#	include <ranges>
#	include <type_traits>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/constant_invocable.hpp"
#	include "../concepts/functable.hpp"
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>)> Functor_ = std::ranges::greater>
	requires(std::is_const_v<Range_> && xieite::concepts::Arithmetic<std::ranges::range_value_t<Range_>> && xieite::concepts::ConstantInvocable<Functor_, std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>>)
	[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<Range_>> modes(Range_& range, Functor_&& comparator = Functor_())
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_const_reference_t<Range_>, std::ranges::range_const_reference_t<Range_>>) {
		std::vector<std::ranges::iterator_t<Range_>> iterators;
		const std::size_t rangeSize = std::ranges::size(range);
		if (rangeSize == 1) {
			iterators.push_back(std::ranges::begin(range));
		}
		if (rangeSize <= 1) {
			return iterators;
		}
		auto previous = std::ranges::begin(range);
		auto iterator = std::ranges::next(previous);
		for (std::size_t i = 1; i < (rangeSize - 1); ++i) {
			if (std::invoke(comparator, *iterator, *previous)) {
				const auto next = std::ranges::next(iterator);
				if (std::invoke(comparator, *iterator, *next)) {
					iterators.push_back(iterator);
				} else if (i == (rangeSize - 2)) {
					iterators.push_back(next);
				}
			} else if (i == 1) {
				iterators.push_back(previous);
			}
			previous = iterator++;
		}
		if (std::ranges::size(range) && !iterators.size()) {
			iterators.push_back(std::ranges::begin(range));
		}
		return iterators;
	}
}

#endif

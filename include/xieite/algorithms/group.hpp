#ifndef XIEITE_HEADER_ALGORITHMS_GROUP
#	define XIEITE_HEADER_ALGORITHMS_GROUP

#	include <concepts>
#	include <cstddef>
#	include <funtional>
#	include <ranges>
#	include <type_traits>
#	include <unordered_map>
#	include <vector>
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, std::invocable<std::ranges::range_reference_t<Range>> Functor>
	[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor, std::ranges::range_reference_t<Range>>, std::vector<std::ranges::const_iterator_t<Range>>> group(Range&& range, Functor&& callback)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>>) {
		return xieite::algorithms::group(range, [&callback](const std::ranges::range_const_reference_t<Range> value, std::size_t) {
			return std::invoke(callback, value);
		});
	}

	template<std::ranges::range Range, std::invocable<std::ranges::range_reference_t<Range>, std::size_t> Functor>
	[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor, std::ranges::range_reference_t<Range>, std::size_t>, std::vector<std::ranges::const_iterator_t<Range>>> group(Range&& range, Functor&& callback)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::size_t>) {
		std::unordered_map<std::invoke_result_t<Functor, std::ranges::range_reference_t<Range>, std::size_t>, std::vector<std::ranges::const_iterator_t<Range>>> groups;
		auto iterator = std::ranges::begin(range);
		const auto end = std::ranges::end(range);
		for (std::size_t i = 0; iterator != end; ++i) {
			groups[std::invoke(callback, *iterator, i)].push_back(iterator);
			++iterator;
		}
		return groups;
	}
}

#endif

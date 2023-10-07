#ifndef XIEITE_HEADER__ALGORITHMS__GROUP
#	define XIEITE_HEADER__ALGORITHMS__GROUP

#	include <concepts>
#	include <cstddef>
#	include <ranges>
#	include <type_traits>
#	include <unordered_map>
#	include <vector>

namespace xieite::algorithms {
	template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>> Callback>
	[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Callback(std::ranges::range_value_t<Range>)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Callback& callback) {
		return xieite::algorithms::group(range, [&callback](std::ranges::range_const_reference_t<Range> value, std::size_t) {
			return callback(value);
		});
	}

	template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>, std::size_t> Callback>
	[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Callback(std::ranges::range_value_t<Range>, std::size_t)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Callback& callback) {
		std::unordered_map<std::invoke_result_t<Callback(std::ranges::range_value_t<Range>, std::size_t)>, std::vector<std::ranges::range_value_t<Range>>> groups;
		std::ranges::iterator_t<const Range&> begin = std::ranges::begin(range);
		std::ranges::const_iterator_t<const Range&> end = std::ranges::end(range);
		for (std::size_t i = 0; begin != end; ++begin, ++i) {
			groups[callback(*begin, i)].push_back(*begin);
		}
		return groups;
	}
}

#endif

#ifndef XIEITE_HEADER_ALGORITHMS_GROUP
#	define XIEITE_HEADER_ALGORITHMS_GROUP

#	include <concepts>
#	include <cstddef>
#	include <iterator>
#	include <type_traits>
#	include <unordered_map>
#	include <vector>

namespace xieite::algorithms {
	template<std::forward_iterator ForwardIterator, std::invocable<std::iter_value_t<ForwardIterator>> Callback>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<ForwardIterator>)>, std::vector<std::iter_value_t<ForwardIterator>>> group(const ForwardIterator begin, const std::sentinel_for<ForwardIterator> auto end, const Callback& callback) {
		return xieite::algorithms::group(begin, end, [&callback](std::iter_reference_t value, std::size_t) -> std::invoke_result_t<Callback(std::iter_value_t<ForwardIterator>)> {
			return callback(value);
		});
	}

	template<std::forward_iterator ForwardIterator, std::invocable<std::iter_value_t<ForwardIterator>, std::size_t> Callback>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<ForwardIterator>, std::size_t)>, std::vector<std::iter_value_t<ForwardIterator>>> group(ForwardIterator begin, const std::sentinel_for<ForwardIterator> auto end, const Callback& callback) {
		std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<ForwardIterator>, std::size_t)>, std::vector<std::iter_value_t<ForwardIterator>>> groups;
		for (std::size_t i = 0; begin != end; ++begin, ++i) {
			groups[callback(*begin, i)].push_back(*begin);
		}
		return groups;
	}
}

#endif

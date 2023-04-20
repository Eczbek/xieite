#pragma once

#include <concepts>
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace xieite::vector {
	template<std::forward_iterator Iterator, std::invocable<std::iterator_traits<Iterator>::value_type> Callback>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Callback(std::iterator_traits<Iterator>::value_type)>, std::vector<std::iterator_traits<Iterator>::value_type>> group(const Iterator begin, const Iterator end, Callback&& callback) noexcept {
		return xieite::algorithms::group(begin, end, [callback = std::forward<Callback>(callback)](std::iterator_traits<Iterator>::value_type& value, std::size_t) noexcept -> std::invoke_result_t<Callback(std::iterator_traits<Iterator>::value_type)> {
			return callback(value);
		});
	}

	template<std::forward_iterator Iterator, std::invocable<std::iterator_traits<Iterator>::value_type, std::size_t> Callback>
	[[nodiscard]]
	std::unordered_map<std::invoke_result_t<Callback(std::iterator_traits<Iterator>::value_type, std::size_t)>, std::vector<std::iterator_traits<Iterator>::value_type>> group(Iterator begin, const Iterator end, Callback&& callback) noexcept {
		std::unordered_map<std::invoke_result_t<Callback(std::iterator_traits<Iterator>::value_type, std::size_t)>, std::vector<std::iterator_traits<Iterator>::value_type>> groups;
		for (std::size_t i = 0; begin != end; ++begin, ++i)
			groups[callback(*begin, i)].push_back(*begin);
		return groups;
	}
}

#pragma once
#include <algorithm> // std::iter_swap
#include <concepts> // std::convertible_to, std::invocable
#include <cstddef> // std::size_t
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <type_traits> // std::invoke_result_t
#include <vector> // std::vector

namespace xieite::algorithms {
	template<std::forward_iterator I, std::invocable<typename std::iterator_traits<I>::value_type> F>
	requires(std::convertible_to<std::invoke_result_t<F, typename std::iterator_traits<I>::value_type&&>, bool>)
	constexpr void partialReverse(I begin, const I end, F&& selector) noexcept {
		std::vector<I> iterators;
		for (; begin != end; ++begin)
			if (selector(*begin))
				iterators.push_back(begin);
		const std::size_t iteratorsSize = iterators.size();
		for (std::size_t i = 0; i < iteratorsSize / 2; ++i)
			std::iter_swap(iterators[i], iterators[iteratorsSize - i - 1]);
	}
}

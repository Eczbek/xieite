#pragma once
#include <algorithm> // std::iter_swap
#include <cstddef> // std::size_t
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <vector> // std::vector
#include <xieite/concepts/SelectorCallback.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator>
	constexpr void partialReverse(Iterator begin, const Iterator end, xieite::concepts::SelectorCallback<typename std::iterator_traits<Iterator>::value_type> auto&& selector) noexcept {
		std::vector<Iterator> iterators;
		for (; begin != end; ++begin)
			if (selector(*begin))
				iterators.push_back(begin);
		const std::size_t iteratorsSize = iterators.size();
		for (std::size_t i = 0; i < iteratorsSize / 2; ++i)
			std::iter_swap(iterators[i], iterators[iteratorsSize - i - 1]);
	}
}

#pragma once
#include <cstddef>
#include <functional>
#include <gcufl/concepts/Comparator.hpp>
#include <iterator>

namespace gcufl::algorithms {
	template<std::forward_iterator I, gcufl::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
	constexpr I findNth(I begin, const I end, std::size_t count, const typename std::iterator_traits<I>::value_type& value, const F& comparator) noexcept {
		for (; begin != end; ++begin)
			if (comparator(*begin, value) && !count--)
				return begin;
		return end;
	}

	template<std::forward_iterator I>
	constexpr I findNth(const I begin, const I end, const std::size_t count, const typename std::iterator_traits<I>::value_type& value) noexcept {
		return gcufl::algorithms::findNth(begin, end, count, value, std::equal_to<const typename std::iterator_traits<I>::value_type>());
	}
}

#pragma once
#include <functional> // std::equal_to
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <xieite/concepts/Comparator.hpp> // xieite::concepts::Comparator

namespace xieite::algorithms {
	template<std::forward_iterator I, xieite::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
	[[nodiscard]]
	constexpr I findNth(I begin, const I end, typename std::iterator_traits<I>::difference_type count, const typename std::iterator_traits<I>::value_type& value, const F& comparator) noexcept {
		for (; begin != end; ++begin)
			if (comparator(*begin, value) && !--count)
				return begin;
		return end;
	}

	template<std::forward_iterator I>
	[[nodiscard]]
	constexpr I findNth(const I begin, const I end, const typename std::iterator_traits<I>::difference_type count, const typename std::iterator_traits<I>::value_type& value) noexcept {
		return xieite::algorithms::findNth(begin, end, count, value, std::equal_to<const typename std::iterator_traits<I>::value_type>());
	}
}

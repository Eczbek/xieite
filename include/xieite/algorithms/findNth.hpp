#pragma once
#include <cstddef> // std::size_t
#include <functional> // std::equal_to
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <utility> // std::forward
#include <xieite/concepts/Comparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator I, xieite::concepts::Comparator<typename std::iterator_traits<I>::value_type> F>
	[[nodiscard]]
	constexpr I findNth(I begin, const I end, typename std::iterator_traits<I>::value_type&& value, std::size_t count, F&& comparator) noexcept {
		for (; begin != end; ++begin)
			if (comparator(*begin, value) && !--count)
				return begin;
		return end;
	}

	template<std::forward_iterator I>
	[[nodiscard]]
	constexpr I findNth(const I begin, const I end, typename std::iterator_traits<I>::value_type&& value, const std::size_t count) noexcept {
		return xieite::algorithms::findNth(begin, end, std::forward<typename std::iterator_traits<I>::value_type>(value), count, std::equal_to<typename std::iterator_traits<I>::value_type>());
	}
}

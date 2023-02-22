#pragma once
#include <cstddef> // std::size_t
#include <functional> // std::equal_to
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <utility> // std::forward
#include <xieite/concepts/Comparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator I, xieite::concepts::Comparator<typename std::iterator_traits<I>::value_type> C = std::equal_to<typename std::iterator_traits<I>::value_type>>
	[[nodiscard]]
	constexpr I findOccurence(I begin, const I end, typename std::iterator_traits<I>::value_type&& value, std::size_t count, C&& comparator = C()) noexcept {
		for (; begin != end; ++begin)
			if (comparator(*begin, value) && !--count)
				return begin;
		return end;
	}
}

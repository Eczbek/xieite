#pragma once
#include <concepts> // std::same_as
#include <functional> // std::equal_to
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <xieite/concepts/ComparatorCallback.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator I, std::forward_iterator J, xieite::concepts::ComparatorCallback<typename std::iterator_traits<I>::value_type> C = std::equal_to<typename std::iterator_traits<I>::value_type>>
	requires(std::same_as<typename std::iterator_traits<I>::value_type, typename std::iterator_traits<J>::value_type>)
	[[nodiscard]]
	constexpr bool rotatedMatch(const I begin1, const I end1, const J begin2, const J end2, C&& comparator = C()) noexcept {
		if (std::distance(begin1, end1) == std::distance(begin2, end2))
			for (I i = begin1; i != end1; ++i) {
				I copy1 = i;
				J copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1)
						copy1 = begin1;
					if (!comparator(*copy1, static_cast<typename std::iterator_traits<I>::value_type>(*copy2)))
						break;
					++copy1;
					++copy2;
				}
				if (copy2 == end2)
					return true;
			}
		return false;
	}
}

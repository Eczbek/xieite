#pragma once

#include <concepts>
#include <functional>
#include <iterator>
#include <xieite/concepts/CallbackComparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator1, std::forward_iterator Iterator2, xieite::concepts::CallbackComparator<typename std::iterator_traits<Iterator1>::value_type> Callback = std::equal_to<typename std::iterator_traits<Iterator1>::value_type>>
	requires(std::same_as<typename std::iterator_traits<Iterator1>::value_type, typename std::iterator_traits<Iterator2>::value_type>)
	[[nodiscard]]
	constexpr bool rotatedMatch(const Iterator1 begin1, const Iterator1 end1, const Iterator2 begin2, const Iterator2 end2, Callback&& comparator = Callback()) noexcept {
		if (std::distance(begin1, end1) == std::distance(begin2, end2))
			for (Iterator1 i = begin1; i != end1; ++i) {
				Iterator1 copy1 = i;
				Iterator2 copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1)
						copy1 = begin1;
					if (!comparator(*copy1, *copy2))
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

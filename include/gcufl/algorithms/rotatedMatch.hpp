#pragma once

#include <functional>
#include <iterator>


namespace gcufl::algorithms {
	template<std::forward_iterator I1, std::forward_iterator I2> requires(std::is_convertible_v<typename std::iterator_traits<I1>::value_type, typename std::iterator_traits<I2>::value_type>)
	bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2, const std::function<bool(const typename std::iterator_traits<I1>::value_type, const typename std::iterator_traits<I1>::value_type)>& comparator = std::equal_to<typename std::iterator_traits<I1>::value_type>()) noexcept {
		const I1 beginCopy1 = begin1;
		const typename std::iterator_traits<I1>::difference_type size = std::distance(begin1, end1);
		if (size == std::distance(begin2, end2))
			for (; begin1 != end1; ++begin1) {
				I1 copy1 = begin1;
				I2 copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1)
						copy1 = beginCopy1;
					if (!comparator(*copy1, static_cast<typename std::iterator_traits<I1>::value_type>(*copy2)))
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

#pragma once

#include <functional>
#include <iterator>


namespace gcufl::algorithms {
	template <std::forward_iterator I1, std::forward_iterator I2>
	bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2) noexcept {
		const typename std::iterator_traits<I1>::difference_type size = std::distance(begin1, end1);
		if (size == std::distance(begin2, end2))
			for (; begin1 != end1; ++begin1) {
				I1 copy1 = begin1;
				I2 copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1)
						std::advance(copy1, -size);
					if (*copy1 != *copy2)
						break;
					++copy1;
					++copy2;
				}
				if (copy2 == end2)
					return true;
			}
		return false;
	}

	template <std::forward_iterator I1, std::forward_iterator I2>
	bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2, const std::function<bool(const typename std::iterator_traits<I1>::value_type&, const typename std::iterator_traits<I2>::value_type&)>& callback) noexcept {
		const typename std::iterator_traits<I1>::difference_type size = std::distance(begin1, end1);
		if (size == std::distance(begin2, end2))
			for (; begin1 != end1; ++begin1) {
				I1 copy1 = begin1;
				I2 copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1)
						std::advance(copy1, -size);
					if (!callback(*copy1, *copy2))
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

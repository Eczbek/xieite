#pragma once

#include <concepts>
#include <iterator>
#include <random>


namespace gcufl {
	namespace algorithms {
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

		template <std::forward_iterator I1, std::forward_iterator I2, std::invocable<const typename std::iterator_traits<I1>::value_type&, const typename std::iterator_traits<I2>::value_type&> C>
		bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2, const C& compare) noexcept {
			const typename std::iterator_traits<I1>::difference_type size = std::distance(begin1, end1);
			if (size == std::distance(begin2, end2))
				for (; begin1 != end1; ++begin1) {
					I1 copy1 = begin1;
					I2 copy2 = begin2;
					while (copy2 != end2) {
						if (copy1 == end1)
							std::advance(copy1, -size);
						if (!compare(*copy1, *copy2))
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
}

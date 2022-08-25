#pragma once

#include <iterator>
#include <random>


namespace gcufl {
	namespace algorithms {
		template <std::input_iterator I1, std::input_iterator I2>
		bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2) noexcept {
			const typename std::iterator_traitss<I1>::difference_type size = std::distance(begin1, end1);
			if (size == std::distance(begin2, end2))
				for (; begin1 != end1; ++begin1) {
					I1 copy1 = begin1;
					I2 copy2 = begin2;
					while (copy2 != end2) {
						if (copy1 == end1)
							std::advance(copy1, -size);
						if (!(*copy1 == *copy2) && !(*copy2 == *copy1))
							break;
						++copy1;
						++copy2;
					}
					if (copy2 == end2)
						return true;
				}
			return false;
		}

		template <std::input_iterator I1, std::input_iterator I2, typename C>
		bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2, const C& compare) noexcept {
			const typename std::iterator_traitss<I1>::difference_type size = std::distance(begin1, end1);
			if (size == std::distance(begin2, end2))
				for (; begin1 != end1; ++begin1) {
					I1 copy1 = begin1;
					I2 copy2 = begin2;
					while (copy2 != end2) {
						if (copy1 == end1)
							std::advance(copy1, -size);
						if (!compare(*copy1, *copy2) && !compare(*copy2, *copy1))
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

#pragma once
#include <concepts> // std::same_as
#include <functional> // std::equal_to
#include <iterator> // std::forward_iterator, std::iterator_traits
#include <xieite/concepts/Comparator.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator I1, std::forward_iterator I2, xieite::concepts::Comparator<typename std::iterator_traits<I1>::value_type> F>
	requires(std::same_as<typename std::iterator_traits<I1>::value_type, typename std::iterator_traits<I2>::value_type>)
	[[nodiscard]]
	constexpr bool rotatedMatch(const I1 begin1, const I1 end1, const I2 begin2, const I2 end2, F&& comparator) noexcept {
		if (std::distance(begin1, end1) == std::distance(begin2, end2))
			for (I1 i = begin1; i != end1; ++i) {
				I1 copy1 = i;
				I2 copy2 = begin2;
				while (copy2 != end2) {
					if (copy1 == end1)
						copy1 = begin1;
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

	template<std::forward_iterator I1, std::forward_iterator I2>
	[[nodiscard]]
	constexpr bool rotatedMatch(const I1 begin1, const I1 end1, const I2 begin2, const I2 end2) noexcept {
		return xieite::algorithms::rotatedMatch(begin1, end1, begin2, end2, std::equal_to<typename std::iterator_traits<I1>::value_type>());
	}
}

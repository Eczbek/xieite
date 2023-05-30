#ifndef XIEITE_HEADER_RANDOM_INTERRUPTABLEUNIFORMDISTRIBUTION
#	define XIEITE_HEADER_RANDOM_INTERRUPTABLEUNIFORMDISTRIBUTION

#	include <algorithm>
#	include <cmath>
#	include <concepts>
#	include <random>
#	include <ranges>
#	include <stdexcept>
#	include <type_traits>
#	include <utility>
#	include <vector>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/concepts/UniformRandomBitGenerator.hpp>
#	include <xieite/math/closestTo.hpp>
#	include <xieite/math/difference.hpp>
#	include <xieite/math/farthestFrom.hpp>

namespace xieite::random {
	template<xieite::concepts::Arithmetic Number>
	class UniformInterruptableDistribution {
	public:
		UniformInterruptableDistribution(const Number begin, const Number end, const xieite::concepts::RangeOf<std::pair<Number, Number>> auto& interruptions) {
			Number begin2 = begin;
			Number end2 = end;
			Number& farthest = xieite::math::farthestFrom<Number>(0.0, begin2, end2);
			this->sign = (farthest >= 0.0) * 2 - 1;
			for (std::pair<Number, Number> interruption : interruptions) {
				if (((interruption.first < begin) || (interruption.first > end)) && ((interruption.first > begin) || (interruption.first < end)) && ((interruption.second < begin) || (interruption.second > end)) && ((interruption.second > begin) || (interruption.second < end))) {
					continue;
				}
				interruption.first = std::clamp(interruption.first, begin, end);
				interruption.second = std::clamp(interruption.second, begin, end);
				const Number difference = (xieite::math::difference(interruption.first, interruption.second) + 1.0) * this->sign;
				if (difference > farthest) {
					throw std::range_error("Cannot exclude entire range");
				}
				farthest -= difference;
				this->interruptions.push_back(interruption);
			}
			this->distribution = UniformDistribution(begin2, end2);
		}

		[[nodiscard]]
		Number operator()(xieite::concepts::UniformRandomBitGenerator auto& generator) const noexcept {
			Number result = this->distribution(generator);
			for (const std::pair<Number, Number> interruption : this->interruptions) {
				const Number closest = xieite::math::closestTo<Number>(0.0, interruption.first, interruption.second);
				if ((this->sign > 0) && (result >= closest) || (this->sign < 0) && (result <= closest)) {
					result += (xieite::math::difference(interruption.first, interruption.second) + 1.0) * this->sign;
				}
			}
			return result;
		}

	private:
		using UniformDistribution = std::conditional_t<std::integral<Number>, std::uniform_int_distribution<Number>, std::uniform_real_distribution<Number>>;

		int sign;
		std::vector<std::pair<Number, Number>> interruptions;
		mutable UniformDistribution distribution;
	};
}

#endif

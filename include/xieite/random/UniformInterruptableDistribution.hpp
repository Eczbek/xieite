#ifndef XIEITE_HEADER_RANDOM_UNIFORMINTERRUPTABLEDISTRIBUTION
#	define XIEITE_HEADER_RANDOM_UNIFORMINTERRUPTABLEDISTRIBUTION

#	include <algorithm>
#	include <cmath>
#	include <concepts>
#	include <iterator>
#	include <random>
#	include <stdexcept>
#	include <type_traits>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/concepts/UniformRandomBitGenerator.hpp>
#	include <xieite/math/Interval.hpp>
#	include <xieite/math/difference.hpp>
#	include <xieite/math/mergeIntervals.hpp>

namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic>
	class UniformInterruptableDistribution {
	public:
		template<xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic>> IntervalRange>
		UniformInterruptableDistribution(const xieite::math::Interval<Arithmetic> interval, const IntervalRange& interruptions) {
			const Arithmetic minimum = std::min(interval.start, interval.end);
			const Arithmetic maximum = std::max(interval.start, interval.end);
			Arithmetic upper = maximum;
			for (const xieite::math::Interval<Arithmetic> interruption : xieite::math::mergeIntervals<Arithmetic>(interruptions)) {
				if (((interruption.start >= minimum) || (interruption.end >= minimum)) && ((interruption.start <= maximum) || (interruption.end <= maximum))) {
					const Arithmetic start = std::clamp(interruption.start, minimum, maximum);
					const Arithmetic end = std::clamp(interruption.end, minimum, maximum);
					const Arithmetic difference = xieite::math::difference(start, end);
					if (upper > (minimum + difference)) {
						upper -= (difference + std::integral<Arithmetic>);
						this->interruptions.push_back(xieite::math::Interval<Arithmetic>(std::min(start, end), difference));
					} else {
						throw std::range_error("Cannot exclude entire interval");
					}
				}
			}
			this->distribution = xieite::random::UniformInterruptableDistribution<Arithmetic>::UniformDistribution(minimum, upper);
			std::ranges::sort(this->interruptions.begin(), this->interruptions.end(), [](const xieite::math::Interval<Arithmetic> interruption1, const xieite::math::Interval<Arithmetic> interruption2) noexcept -> Arithmetic {
				return interruption1.start < interruption2.start;
			});
		}

		template<xieite::concepts::UniformRandomBitGenerator UniformRandomBitGenerator>
		[[nodiscard]]
		Arithmetic operator()(UniformRandomBitGenerator& generator) const noexcept {
			Arithmetic result = this->distribution(generator);
			for (const xieite::math::Interval<Arithmetic> interruption : this->interruptions) {
				if (result >= interruption.start) {
					result += (interruption.end + std::integral<Arithmetic>);
				}
			}
			return result;
		}

	private:
		using UniformDistribution = std::conditional_t<std::integral<Arithmetic>, std::uniform_int_distribution<Arithmetic>, std::uniform_real_distribution<Arithmetic>>;

		mutable UniformDistribution distribution;
		std::vector<xieite::math::Interval<Arithmetic>> interruptions;
	};
}

#endif

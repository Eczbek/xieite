#ifndef XIEITE_HEADER_RANDOM_UNIFORM_INTERRUPTABLE_DISTRIBUTION
#	define XIEITE_HEADER_RANDOM_UNIFORM_INTERRUPTABLE_DISTRIBUTION

#	include <algorithm>
#	include <concepts>
#	include <iterator>
#	include <random>
#	include <utility>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/range_of.hpp"
#	include "../concepts/uniform_random_bit_generator.hpp"
#	include "../macros/forward.hpp"
#	include "../math/interval.hpp"
#	include "../math/difference.hpp"
#	include "../math/merge_intervals.hpp"
#	include "../random/uniform_distribution.hpp"

namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic_>
	struct UniformInterruptableDistribution {
	public:
		template<xieite::concepts::RangeOf<xieite::math::Interval<Arithmetic_>> IntervalRange_>
		UniformInterruptableDistribution(const xieite::math::Interval<Arithmetic_> interval, IntervalRange_&& interruptions) noexcept {
			const Arithmetic_ minimum = std::min(interval.start, interval.end);
			const Arithmetic_ maximum = std::max(interval.start, interval.end);
			Arithmetic_ upper = maximum;
			for (const xieite::math::Interval<Arithmetic_> interruption : xieite::math::mergeIntervals<Arithmetic_>(XIEITE_FORWARD(interruptions))) {
				if (((interruption.start >= minimum) || (interruption.end >= minimum)) && ((interruption.start <= maximum) || (interruption.end <= maximum))) {
					const Arithmetic_ start = std::clamp(interruption.start, minimum, maximum);
					const Arithmetic_ end = std::clamp(interruption.end, minimum, maximum);
					const Arithmetic_ difference = xieite::math::difference(start, end);
					if (upper <= (minimum + difference)) {
						std::unreachable();
					}
					upper -= difference + std::integral<Arithmetic_>;
					this->interruptions.push_back(xieite::math::Interval<Arithmetic_>(std::min(start, end), difference));
				}
			}
			this->distribution = xieite::random::UniformDistribution<Arithmetic_>(minimum, upper);
			std::ranges::sort(this->interruptions.begin(), this->interruptions.end(), [](const xieite::math::Interval<Arithmetic_> interruption1, const xieite::math::Interval<Arithmetic_> interruption2) {
				return interruption1.start < interruption2.start;
			});
		}

		template<std::uniform_random_bit_generator UniformRandomBitGenerator_>
		[[nodiscard]] Arithmetic_ operator()(UniformRandomBitGenerator_& generator) noexcept {
			Arithmetic_ result = this->distribution(generator);
			for (const xieite::math::Interval<Arithmetic_> interruption : this->interruptions) {
				if (result >= interruption.start) {
					result += interruption.end + std::integral<Arithmetic_>;
				}
			}
			return result;
		}

	private:
		xieite::random::UniformDistribution<Arithmetic_> distribution;
		std::vector<xieite::math::Interval<Arithmetic_>> interruptions;
	};
}

#endif

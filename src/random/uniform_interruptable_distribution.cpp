module;

#include <xieite/forward.hpp>

export module xieite:random.UniformInterruptableDistribution;

import std;
import :concepts.Arithmetic;
import :math.Interval;
import :math.difference;
import :math.mergeIntervals;
import :random.UniformDistribution;

export namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct UniformInterruptableDistribution {
	public:
		template<std::ranges::input_range IntervalRange>
		requires(std::convertible_to<std::ranges::range_value_t<IntervalRange>, xieite::math::Interval<Arithmetic>>)
		UniformInterruptableDistribution(const xieite::math::Interval<Arithmetic> interval, IntervalRange&& interruptions) {
			const Arithmetic minimum = std::min(interval.start, interval.end);
			const Arithmetic maximum = std::max(interval.start, interval.end);
			Arithmetic upper = maximum;
			for (const xieite::math::Interval<Arithmetic> interruption : xieite::math::mergeIntervals<Arithmetic>(XIEITE_FORWARD(interruptions))) {
				if (((interruption.start >= minimum) || (interruption.end >= minimum)) && ((interruption.start <= maximum) || (interruption.end <= maximum))) {
					const Arithmetic start = std::clamp(interruption.start, minimum, maximum);
					const Arithmetic end = std::clamp(interruption.end, minimum, maximum);
					const Arithmetic difference = xieite::math::difference(start, end);
					if (upper <= (minimum + difference)) {
						throw std::out_of_range("must not exclude entire interval");
					}
					upper -= difference + std::integral<Arithmetic>;
					this->interruptions.push_back(xieite::math::Interval<Arithmetic>(std::min(start, end), difference));
				}
			}
			this->distribution = xieite::random::UniformDistribution<Arithmetic>(minimum, upper);
			std::ranges::sort(this->interruptions.begin(), this->interruptions.end(), [](const xieite::math::Interval<Arithmetic> interruption1, const xieite::math::Interval<Arithmetic> interruption2) -> bool {
				return interruption1.start < interruption2.start;
			});
		}

		template<std::uniform_random_bit_generator UniformRandomBitGenerator>
		[[nodiscard]] Arithmetic operator()(UniformRandomBitGenerator& generator) noexcept {
			Arithmetic result = this->distribution(generator);
			for (const xieite::math::Interval<Arithmetic> interruption : this->interruptions) {
				if (result >= interruption.start) {
					result += interruption.end + std::integral<Arithmetic>;
				}
			}
			return result;
		}

	private:
		xieite::random::UniformDistribution<Arithmetic> distribution;
		std::vector<xieite::math::Interval<Arithmetic>> interruptions;
	};
}

module;

#include <xieite/forward.hpp>

export module xieite:random.UniformInterruptableDistribution;

import std;
import :concepts.Arithmetic;
import :math.Interval;
import :math.difference;
import :math.isBetweenFixed;
import :math.limitsFixed;
import :math.mergeIntervals;
import :random.UniformDistribution;

export namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic>
	struct UniformInterruptableDistribution {
	public:
		template<std::ranges::input_range IntervalRange>
		requires(std::convertible_to<std::ranges::range_value_t<IntervalRange>, xieite::math::Interval<Arithmetic>>)
		UniformInterruptableDistribution(const xieite::math::Interval<Arithmetic> interval, IntervalRange&& interruptions) {
			const auto [minimum, maximum] = xieite::math::limitsFixed(interval.start, interval.end);
			Arithmetic upper = maximum;
			for (auto [start, end] : xieite::math::mergeIntervals(XIEITE_FORWARD(interruptions))) {
				if (!xieite::math::isBetweenFixed(start, minimum, maximum) || !xieite::math::isBetweenFixed(end, minimum, maximum)) {
					continue;
				}
				start = std::clamp(start, minimum, maximum);
				end = std::clamp(end, minimum, maximum);
				const auto difference = static_cast<Arithmetic>(xieite::math::difference(start, end));
				if (upper <= (minimum + difference)) {
					throw std::out_of_range("must not exclude entire interval");
				}
				upper -= difference + std::integral<Arithmetic>;
				this->interruptions.push_back(xieite::math::Interval<Arithmetic>(std::min(start, end), difference));
			}
			this->distribution = xieite::random::UniformDistribution<Arithmetic>(minimum, upper);
			std::ranges::sort(this->interruptions, std::ranges::less(), &xieite::math::Interval<Arithmetic>::start);
		}

		template<std::uniform_random_bit_generator UniformRandomBitGenerator>
		[[nodiscard]] Arithmetic operator()(UniformRandomBitGenerator& generator) noexcept {
			Arithmetic result = this->distribution(generator);
			for (const auto [start, end] : this->interruptions) {
				if (result >= start) {
					result += end + std::integral<Arithmetic>;
				}
			}
			return result;
		}

	private:
		xieite::random::UniformDistribution<Arithmetic> distribution;
		std::vector<xieite::math::Interval<Arithmetic>> interruptions;
	};
}

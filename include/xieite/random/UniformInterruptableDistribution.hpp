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
	template<xieite::concepts::Arithmetic Number>
	class UniformInterruptableDistribution {
	public:
		UniformInterruptableDistribution(const xieite::math::Interval<Number> interval, const xieite::concepts::RangeOf<xieite::math::Interval<Number>> auto& interruptions) {
			const Number lower = std::min(interval.start, interval.end);
			const Number upper = std::max(interval.start, interval.end);
			Number maximum = upper;
			for (const xieite::math::Interval<Number> interruption : xieite::math::mergeIntervals<Number>(interruptions)) {
				const Number start = std::clamp(interruption.start, lower, upper);
				const Number end = std::clamp(interruption.end, lower, upper);
				if (((start >= lower) && (start <= upper)) || ((end >= lower) && (end <= upper))) {
					const Number difference = xieite::math::difference(start, end);
					if (maximum > (lower + difference)) {
						maximum -= (difference + std::integral<Number>);
						this->interruptions.push_back(xieite::math::Interval<Number>(std::min(start, end), difference));
					} else {
						throw std::range_error("Cannot exclude entire interval");
					}
				}
			}
			this->distribution = xieite::random::UniformInterruptableDistribution<Number>::UniformDistribution(lower, maximum);
			std::ranges::sort(std::ranges::begin(this->interruptions), std::ranges::end(this->interruptions), [](const xieite::math::Interval<Number> interruption1, const xieite::math::Interval<Number> interruption2) noexcept -> Number {
				return interruption1.start < interruption2.start;
			});
		}

		[[nodiscard]]
		Number operator()(xieite::concepts::UniformRandomBitGenerator auto& generator) const noexcept {
			Number result = this->distribution(generator);
			for (const xieite::math::Interval<Number> interruption : this->interruptions) {
				if (result >= interruption.start) {
					result += (interruption.end + std::integral<Number>);
				}
			}
			return result;
		}

	private:
		using UniformDistribution = std::conditional_t<std::integral<Number>, std::uniform_int_distribution<Number>, std::uniform_real_distribution<Number>>;

		mutable UniformDistribution distribution;
		std::vector<xieite::math::Interval<Number>> interruptions;
	};
}

#endif

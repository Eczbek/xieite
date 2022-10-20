#pragma once
#include <algorithm>
#include <concepts>
#include <cmath>
#include <gcufl/concepts/UniformRandomGenerator.hpp>
#include <gcufl/math/closestTo.hpp>
#include <gcufl/math/difference.hpp>
#include <gcufl/math/farthestFrom.hpp>
#include <gcufl/math/NumberRange.hpp>
#include <random>
#include <stdexcept>
#include <vector>

namespace gcufl::random {
	template<typename>
	class InterruptableUniformDistribution {};

	template<std::integral N>
	class InterruptableUniformDistribution<N> {
	private:
		int sign;
		std::vector<gcufl::math::NumberRange<N>> interruptions;
		std::uniform_int_distribution<N> distribution;
	
	public:
		[[nodiscard]]
		constexpr InterruptableUniformDistribution(const N begin, const N end, const std::vector<gcufl::math::NumberRange<N>>& interruptions) {
			N begin2 = begin;
			N end2 = end;
			N& farthest = gcufl::math::farthestFrom(0, begin2, end2);
			sign = (farthest >= 0) * 2 - 1;
			for (gcufl::math::NumberRange<N> interruption : interruptions) {
				if ((interruption.begin < begin || interruption.begin > end) && (interruption.begin > begin || interruption.begin < end) && (interruption.end < begin || interruption.end > end) && (interruption.end > begin || interruption.end < end))
					continue;
				interruption.begin = std::clamp(interruption.begin, begin, end);
				interruption.end = std::clamp(interruption.end, begin, end);
				const N difference = (static_cast<N>(gcufl::math::difference(interruption.begin, interruption.end)) + 1) * sign;
				if (difference >= farthest)
					throw std::domain_error("Cannot exclude entire range");
				farthest -= difference;
				this->interruptions.push_back(interruption);
			}
			distribution = std::uniform_int_distribution<N>(std::min(begin2, end2), std::max(begin2, end2));
		}

		[[nodiscard]]
		template<gcufl::concepts::UniformRandomGenerator G>
		constexpr N operator()(G& generator) noexcept {
			N result = distribution(generator);
			for (const gcufl::math::NumberRange<N> interruption : interruptions) {
				const N closest = gcufl::math::closestTo(0, interruption.begin, interruption.end);
				if (sign > 0 && result >= closest || sign < 0 && result <= closest)
					result += (static_cast<N>(gcufl::math::difference(interruption.begin, interruption.end)) + 1) * sign;
			}
			return result;
		}
	};

	template<std::floating_point N>
	class InterruptableUniformDistribution<N> {
	private:
		int sign;
		std::vector<gcufl::math::NumberRange<N>> interruptions;
		std::uniform_real_distribution<N> distribution;

	public:
		[[nodiscard]]
		constexpr InterruptableUniformDistribution(const N begin, const N end, const std::vector<gcufl::math::NumberRange<N>>& interruptions) {
			N begin2 = begin;
			N end2 = end;
			N& farthest = gcufl::math::farthestFrom(0.0, begin2, end2);
			sign = (farthest >= 0) * 2 - 1;
			for (gcufl::math::NumberRange<N> interruption : interruptions) {
				if ((interruption.begin < begin || interruption.begin > end) && (interruption.begin > begin || interruption.begin < end) && (interruption.end < begin || interruption.end > end) && (interruption.end > begin || interruption.end < end))
					continue;
				interruption.begin = std::clamp(interruption.begin, begin, end);
				interruption.end = std::clamp(interruption.end, begin, end);
				const N difference = (static_cast<N>(gcufl::math::difference(interruption.begin, interruption.end)) + 1) * sign;
				if (difference >= farthest)
					throw std::domain_error("Cannot exclude entire range");
				farthest -= difference;
				this->interruptions.push_back(interruption);
			}
			distribution = std::uniform_real_distribution<N>(std::min(begin2, end2), std::max(begin2, end2));
		}

		[[nodiscard]]
		template<gcufl::concepts::UniformRandomGenerator G>
		constexpr N operator()(G& generator) noexcept {
			N result = distribution(generator);
			for (const gcufl::math::NumberRange<N> interruption : interruptions) {
				const N closest = gcufl::math::closestTo(0.0, interruption.begin, interruption.end);
				if (sign > 0 && result >= closest || sign < 0 && result <= closest)
					result += (static_cast<N>(gcufl::math::difference(interruption.begin, interruption.end)) + 1) * sign;
			}
			return result;
		}
	};
}

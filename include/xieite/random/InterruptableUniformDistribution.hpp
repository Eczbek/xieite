#pragma once
#include <algorithm>
#include <concepts>
#include <cmath>
#include <random>
#include <stdexcept>
#include <utility>
#include <vector>
#include <xieite/concepts/UniformRandomGenerator.hpp>
#include <xieite/math/closestTo.hpp>
#include <xieite/math/difference.hpp>
#include <xieite/math/farthestFrom.hpp>

namespace xieite::random {
	template<typename>
	class InterruptableUniformDistribution {};

	template<std::integral N>
	class InterruptableUniformDistribution<N> {
	private:
		int sign;
		std::vector<std::pair<N, N>> interruptions;
		std::uniform_int_distribution<N> distribution;
	
	public:
		constexpr InterruptableUniformDistribution(const N begin, const N end, const std::vector<std::pair<N, N>>& interruptions) {
			N begin2 = begin;
			N end2 = end;
			N& farthest = xieite::math::farthestFrom(0, begin2, end2);
			sign = (farthest >= 0) * 2 - 1;
			for (std::pair<N, N> interruption : interruptions) {
				if ((interruption.first < begin || interruption.first > end) && (interruption.first > begin || interruption.first < end) && (interruption.second < begin || interruption.second > end) && (interruption.second > begin || interruption.second < end))
					continue;
				interruption.first = std::clamp(interruption.first, begin, end);
				interruption.second = std::clamp(interruption.second, begin, end);
				const N difference = (static_cast<N>(xieite::math::difference(interruption.first, interruption.second)) + 1) * sign;
				if (difference >= farthest)
					throw std::domain_error("Cannot exclude entire range");
				farthest -= difference;
				this->interruptions.push_back(interruption);
			}
			distribution = std::uniform_int_distribution<N>(std::min(begin2, end2), std::max(begin2, end2));
		}

		[[nodiscard]]
		template<xieite::concepts::UniformRandomGenerator G>
		constexpr N operator()(G& generator) noexcept {
			N result = distribution(generator);
			for (const std::pair<N, N> interruption : interruptions) {
				const N closest = xieite::math::closestTo(0, interruption.first, interruption.second);
				if (sign > 0 && result >= closest || sign < 0 && result <= closest)
					result += (static_cast<N>(xieite::math::difference(interruption.first, interruption.second)) + 1) * sign;
			}
			return result;
		}
	};

	template<std::floating_point N>
	class InterruptableUniformDistribution<N> {
	private:
		int sign;
		std::vector<std::pair<N, N>> interruptions;
		std::uniform_real_distribution<N> distribution;

	public:
		constexpr InterruptableUniformDistribution(const N begin, const N end, const std::vector<std::pair<N, N>>& interruptions) {
			N begin2 = begin;
			N end2 = end;
			N& farthest = xieite::math::farthestFrom(0.0, begin2, end2);
			sign = (farthest >= 0) * 2 - 1;
			for (std::pair<N, N> interruption : interruptions) {
				if ((interruption.first < begin || interruption.first > end) && (interruption.first > begin || interruption.first < end) && (interruption.second < begin || interruption.second > end) && (interruption.second > begin || interruption.second < end))
					continue;
				interruption.first = std::clamp(interruption.first, begin, end);
				interruption.second = std::clamp(interruption.second, begin, end);
				const N difference = (static_cast<N>(xieite::math::difference(interruption.first, interruption.second)) + 1) * sign;
				if (difference >= farthest)
					throw std::domain_error("Cannot exclude entire range");
				farthest -= difference;
				this->interruptions.push_back(interruption);
			}
			distribution = std::uniform_real_distribution<N>(std::min(begin2, end2), std::max(begin2, end2));
		}

		[[nodiscard]]
		template<xieite::concepts::UniformRandomGenerator G>
		constexpr N operator()(G& generator) noexcept {
			N result = distribution(generator);
			for (const std::pair<N, N> interruption : interruptions) {
				const N closest = xieite::math::closestTo(0.0, interruption.first, interruption.second);
				if (sign > 0 && result >= closest || sign < 0 && result <= closest)
					result += (static_cast<N>(xieite::math::difference(interruption.first, interruption.second)) + 1) * sign;
			}
			return result;
		}
	};
}

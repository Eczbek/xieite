#ifndef XIEITE_HEADER_RANDOM_BAGUNIFORMDISTRIBUTION
#	define XIEITE_HEADER_RANDOM_BAGUNIFORMDISTRIBUTION

#	include <cmath>
#	include <concepts>
#	include <random>
#	include <set>
#	include <utility>
#	include <xieite/math/difference.hpp>
#	include <xieite/random/UniformInterruptableDistribution.hpp>

namespace xieite::random {
	template<std::integral Integral>
	class UniformBagDistribution final {
	public:
		UniformBagDistribution(const Integral begin, const Integral end) noexcept
		: begin(begin), end(end) {}

		[[nodiscard]]
		Integral operator()(xieite::concepts::UniformRandomBitGenerator auto& generator) const noexcept {
			static std::set<std::pair<Integral, Integral>> previousResults;
			const Integral result = xieite::random::UniformInterruptableDistribution<Integral>(this->begin, this->end, previousResults)(generator);
			if (previousResults.size() < xieite::math::difference(this->begin, this->end)) {
				previousResults.insert(std::pair<Integral, Integral>(result, result));
			} else {
				previousResults.clear();
			}
			return result;
		}

	private:
		const Integral begin;
		const Integral end;
	};
}

#endif

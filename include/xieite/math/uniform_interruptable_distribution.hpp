#ifndef DETAIL_XIEITE_HEADER_MATH_UNIFORM_INTERRUPTABLE_DISTRIBUTION
#	define DETAIL_XIEITE_HEADER_MATH_UNIFORM_INTERRUPTABLE_DISTRIBUTION
#
#	include <algorithm>
#	include <concepts>
#	include <functional>
#	include <stdexcept>
#	include <ranges>
#	include <vector>
#	include "../math/between.hpp"
#	include "../math/diff.hpp"
#	include "../math/interval.hpp"
#	include "../math/merge_intervals.hpp"
#	include "../math/minmax.hpp"
#	include "../math/uniform_distribution.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	struct uniform_interruptable_distribution {
	public:
		template<std::ranges::input_range Range>
		requires(std::convertible_to<std::ranges::range_value_t<Range>, xieite::interval<Arith>>)
		[[nodiscard]] uniform_interruptable_distribution(xieite::interval<Arith> interval, Range&& interruptions) {
			const auto [min, max] = xieite::minmax(interval.start, interval.end);
			Arith upper = max;
			for (auto [start, end] : xieite::merge_intervals(XIEITE_FWD(interruptions))) {
				if (!xieite::between(start, min, max) || !xieite::between(end, min, max)) {
					continue;
				}
				start = std::clamp(start, min, max);
				end = std::clamp(end, min, max);
				const auto diff = static_cast<Arith>(xieite::diff(start, end));
				if (upper <= (min + diff)) {
					throw std::out_of_range("must not exclude entire interval");
				}
				upper -= diff + std::integral<Arith>;
				this->interruptions.push_back(xieite::interval<Arith>(std::min(start, end), diff));
			}
			this->distribution = xieite::uniform_distribution<Arith>(min, upper);
			std::ranges::sort(this->interruptions, std::less(), &xieite::interval<Arith>::start);
		}

		template<std::uniform_random_bit_generator Generator>
		[[nodiscard]] Arith operator()(Generator& generator) noexcept {
			Arith result = this->distribution(generator);
			for (auto [start, end] : this->interruptions) {
				if (result >= start) {
					result += end + std::integral<Arith>;
				}
			}
			return result;
		}

	private:
		xieite::uniform_distribution<Arith> distribution;
		std::vector<xieite::interval<Arith>> interruptions;
	};
}

#endif

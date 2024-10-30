module;

#include <xieite/fwd.hpp>

export module xieite:uniform_interrupt_dist;

import std;
import :between_fixed;
import :diff;
import :interval;
import :is_arith;
import :limits_fixed;
import :merge_intervals;
import :uniform_dist;

export namespace xieite {
	template<xieite::is_arith T>
	struct uniform_interrupt_dist {
	public:
		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::interval<T>>)
		uniform_interrupt_dist(xieite::interval<T> interval, R&& interruptions) {
			const auto [min, max] = xieite::limits_fixed(interval.start, interval.end);
			T upper = max;
			for (auto [start, end] : xieite::merge_intervals(XIEITE_FWD(interruptions))) {
				if (!xieite::between_fixed(start, min, max) || !xieite::between_fixed(end, min, max)) {
					continue;
				}
				start = std::clamp(start, min, max);
				end = std::clamp(end, min, max);
				const auto diff = static_cast<T>(xieite::diff(start, end));
				if (upper <= (min + diff)) {
					throw std::out_of_range("must not exclude entire interval");
				}
				upper -= diff + std::integral<T>;
				this->interruptions.push_back(xieite::interval<T>(std::min(start, end), diff));
			}
			this->dist = xieite::uniform_dist<T>(min, upper);
			std::ranges::sort(this->interruptions, std::ranges::less(), &xieite::interval<T>::start);
		}

		template<std::uniform_random_bit_generator G>
		[[nodiscard]] T operator()(G& gen) noexcept {
			T result = this->dist(gen);
			for (auto [start, end] : this->interruptions) {
				if (result >= start) {
					result += end + std::integral<T>;
				}
			}
			return result;
		}

	private:
		xieite::uniform_dist<T> dist;
		std::vector<xieite::interval<T>> interruptions;
	};
}

module;

#include <xieite/fwd.hpp>

export module xieite:uniform_interrupt_distr;

import std;
import :betw;
import :diff;
import :intv;
import :is_arith;
import :minmax;
import :merge_intv;
import :uniform_distr;

export namespace xieite {
	template<xieite::is_arith T>
	struct uniform_interrupt_distr {
	public:
		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::intv<T>>)
		uniform_interrupt_distr(xieite::intv<T> intv, R&& interruptions) {
			const auto [min, max] = xieite::minmax(intv.start, intv.end);
			T upper = max;
			for (auto [start, end] : xieite::merge_intv(XIEITE_FWD(interruptions))) {
				if (!xieite::betw(start, min, max) || !xieite::betw(end, min, max)) {
					continue;
				}
				start = std::clamp(start, min, max);
				end = std::clamp(end, min, max);
				const T diff = static_cast<T>(xieite::diff(start, end));
				if (upper <= (min + diff)) {
					throw std::out_of_range("must not exclude entire intv");
				}
				upper -= diff + std::integral<T>;
				this->interruptions.push_back(xieite::intv<T>(std::min(start, end), diff));
			}
			this->distr = xieite::uniform_distr<T>(min, upper);
			std::ranges::sort(this->interruptions, std::ranges::less(), &xieite::intv<T>::start);
		}

		template<std::uniform_random_bit_generator G>
		[[nodiscard]] T operator()(G& gen) noexcept {
			T result = this->distr(gen);
			for (auto [start, end] : this->interruptions) {
				if (result >= start) {
					result += end + std::integral<T>;
				}
			}
			return result;
		}

	private:
		xieite::uniform_distr<T> distr;
		std::vector<xieite::intv<T>> interruptions;
	};
}

#pragma once

#include <algorithm>
#include <concepts>
#include <functional>
#include <stdexcept>
#include <ranges>
#include <vector>
#include "../math/betw.hpp"
#include "../math/diff.hpp"
#include "../math/intv.hpp"
#include "../math/mrgintv.hpp"
#include "../math/minmax.hpp"
#include "../math/uniformdistr.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	struct uniforminterruptdistr {
	public:
		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, x4::intv<T>>)
		[[nodiscard]] uniforminterruptdistr(x4::intv<T> intv, R&& interrupts) {
			const auto [min, max] = x4::minmax(intv.start, intv.end);
			T upper = max;
			for (auto [start, end] : x4::mrgintv(X4FWD(interrupts))) {
				if (!x4::betw(start, min, max) || !x4::betw(end, min, max)) {
					continue;
				}
				start = std::clamp(start, min, max);
				end = std::clamp(end, min, max);
				const auto diff = static_cast<T>(x4::diff(start, end));
				if (upper <= (min + diff)) {
					throw std::out_of_range("must not exclude entire intv");
				}
				upper -= diff + std::integral<T>;
				this->interrupts.push_back(x4::intv<T>(std::min(start, end), diff));
			}
			this->distr = x4::uniformdistr<T>(min, upper);
			std::ranges::sort(this->interrupts, std::ranges::less(), &x4::intv<T>::start);
		}

		template<std::uniform_random_bit_generator G>
		[[nodiscard]] T operator()(G& gen) noexcept {
			T result = this->distr(gen);
			for (auto [start, end] : this->interrupts) {
				if (result >= start) {
					result += end + std::integral<T>;
				}
			}
			return result;
		}

	private:
		x4::uniformdistr<T> distr;
		std::vector<x4::intv<T>> interrupts;
	};
}

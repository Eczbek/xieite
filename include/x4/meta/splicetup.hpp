#pragma once

#include <cstddef>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../meta/fwdtup.hpp"
#include "../meta/tupsz.hpp"
#include "../pp/fwd.hpp"
#include "../trait/isspec.hpp"

namespace x4 {
	template<std::size_t start, std::size_t end = start, x4::istuple_like Tuple0, x4::istuple_like Tuple1 = std::tuple<>>
	[[nodiscard]] constexpr auto splicetup(Tuple0&& tuple0, Tuple1&& tuple1 = {}) noexcept {
		static_assert(start <= x4::tupsz<Tuple0>, "start index must be within tuple size");
		static_assert(end <= x4::tupsz<Tuple0>, "end index must be within tuple size");
		return std::tuple_cat(
			x4::unroll<start>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<i>(std::move(tuple0))...);
			}),
			x4::fwdtup(X4FWD(tuple1)),
			x4::unroll<(x4::tupsz<Tuple0> - end)>([&tuple0]<std::size_t... i> {
				return std::forward_as_tuple(std::get<(end + i)>(std::move(tuple0))...);
			})
		);
	}
}

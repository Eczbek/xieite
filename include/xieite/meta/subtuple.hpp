#pragma once

#include <algorithm>
#include <cstddef>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../meta/tuple_size.hpp"
#include "../trait/is_tuple_like.hpp"

namespace xieite {
	template<std::size_t start, std::size_t end = -1uz>
	[[nodiscard]] constexpr auto subtuple(xieite::is_tuple_like auto&& tuple) noexcept {
		static constexpr std::size_t size = xieite::tuple_size<decltype(tuple)>;
		return xieite::unroll<(std::min(end, size) - std::min(start, size))>(
			[&tuple]<std::size_t... i> {
				return std::forward_as_tuple(std::get<(std::min(start, size) + i)>(std::move(tuple))...);
			}
		);
	}
}

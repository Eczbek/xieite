#pragma once

#include <cstddef>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../meta/tuple_size.hpp"
#include "../trait/is_tuple_like.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto reverse_tuple(xieite::is_tuple_like auto&& tuple) noexcept {
		static constexpr std::size_t size = xieite::tuple_size<decltype(tuple)>;
		return xieite::unroll<size>([&tuple]<std::size_t... i> {
			return std::forward_as_tuple(std::get<(size - i - 1)>(std::move(tuple))...);
		});
	}
}

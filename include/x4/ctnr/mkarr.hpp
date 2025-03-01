#pragma once

#include <array>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <ranges>
#include <utility>
#include "../fn/cast.hpp"
#include "../fn/unroll.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"

namespace x4 {
	template<typename V, std::size_t size, std::ranges::input_range R = std::initializer_list<V>, x4::isinvoc<V(std::ranges::range_common_reference_t<R>)> F = decltype(x4::cast<V>)>
	[[nodiscard]] constexpr std::array<V, size> mkarr(R&& range, F&& conv = {})
	noexcept(x4::isnoexinvoc<F, V(std::ranges::range_common_reference_t<R>)>) {
		return x4::unroll<size>([&range, &conv]<std::size_t... i> -> std::array<V, size> {
			auto iter = std::ranges::begin(range);
			return std::array<V, size> {
				([&conv, &iter] -> decltype(auto) {
					if constexpr (i > 0) {
						++iter;
					}
					return std::invoke(conv, std::forward_like<R>(*iter));
				})()...
			};
		});
	}
}

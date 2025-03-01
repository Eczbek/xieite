#pragma once

#include <array>
#include <cstddef>
#include <functional>
#include "../fn/unroll.hpp"
#include "../pp/ar.hpp"
#include "../pp/lift.hpp"

namespace x4 {
	template<typename F, typename V, std::size_t size>
	[[nodiscard]] constexpr auto applyarr(F&& fn, const std::array<V, size>& array)
		X4AR(x4::unroll<size>(
			[]<std::size_t... i>(F&& fn, const auto& array) static
				X4AR(std::invoke(X4FWD(fn), array[i]...)),
			X4FWD(fn),
			array
		))

	template<typename T, typename V, std::size_t size>
	[[nodiscard]] constexpr T applyarr(const std::array<V, size>& array)
		X4ARRET(x4::applyarr(X4LIFT(T), array))
}

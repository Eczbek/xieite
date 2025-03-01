#pragma once

#include <array>
#include <bit>
#include <cstddef>
#include "../fn/unroll.hpp"

namespace x4 {
	struct bytefill {
		char value;

		template<std::integral T>
		[[nodiscard]] explicit constexpr bytefill(T n) noexcept
		: value(static_cast<char>(n)) {}

		template<typename T>
		[[nodiscard]] explicit(false) constexpr operator T() const noexcept {
			return x4::unroll<sizeof(T)>([this]<std::size_t... i> -> std::array<char, sizeof(T)> {
				return std::bit_cast<T>(std::array<char, sizeof(T)> { (i, this->value)... });
			});
		}
	};
}

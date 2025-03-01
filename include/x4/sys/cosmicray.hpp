#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

namespace x4 {
	inline void cosmicray(std::size_t bytes) noexcept {
		const std::size_t size = bytes / sizeof(std::intmax_t);
		const auto detector = std::make_unique<volatile const char[]>(size);
		for (std::size_t i = 0; !detector[++i %= size];);
	}
}

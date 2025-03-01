#pragma once

#include <cstddef>
#include <string_view>
#include "../math/sgncast.hpp"

namespace x4 {
	[[nodiscard]] constexpr std::size_t djb2(std::string_view str) noexcept {
		std::size_t result = 5381;
		for (char c : str) {
			result = result * 33 + x4::sgncast<std::size_t>(c);
		}
		return result;
	}
}

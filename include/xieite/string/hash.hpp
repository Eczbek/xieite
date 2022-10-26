#pragma once
#include <string_view>

namespace xieite::string {
	[[nodiscard]]
	constexpr unsigned long long hash(const std::string_view string) noexcept {
		unsigned long long result = 5381;
		for (const char character : string)
			result = result * 33 + character;
		return result;
	}
}

#pragma once

#include <string>
#include <string_view>

namespace xieite::strings::literals {
	template<char... characters>
	[[nodiscard]] constexpr std::string operator""_stringify() noexcept {
		return std::string {
			characters...
		};
	}
}

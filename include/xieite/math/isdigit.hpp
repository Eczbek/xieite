#pragma once

#include "../trait/is_ch.hpp"

namespace xieite {
	template<xieite::is_ch Ch = char>
	[[nodiscard]] constexpr bool isdigit(Ch c) noexcept {
		return (c >= '0') && (c <= '9');
	}
}

// https://timsong-cpp.github.io/cppwp/n4950/lex.charset#5.sentence-5

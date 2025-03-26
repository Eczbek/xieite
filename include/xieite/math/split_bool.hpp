#pragma once

#include "../math/ssize_t.hpp"

namespace xieite {
	[[nodiscard]] constexpr xieite::ssize_t split_bool(bool x) noexcept {
		return x * 2 - 1;
	}
}

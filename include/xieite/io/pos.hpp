#pragma once

#include "../math/ssize_t.hpp"

namespace xieite {
	struct pos {
		xieite::ssize_t row;
		xieite::ssize_t col;

		[[nodiscard]] friend bool operator==(const xieite::pos&, const xieite::pos&) = default;
	};
}

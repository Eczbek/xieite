#pragma once

namespace xieite {
	struct pos {
		int row;
		int col;

		[[nodiscard]] friend bool operator==(const xieite::pos&, const xieite::pos&) = default;
	};
}

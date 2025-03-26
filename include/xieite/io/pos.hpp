#ifndef DETAIL_XIEITE_HEADER_IO_POS
#	define DETAIL_XIEITE_HEADER_IO_POS
#
#	include "../math/ssize_t.hpp"

namespace xieite {
	struct pos {
		xieite::ssize_t row;
		xieite::ssize_t col;

		[[nodiscard]] friend bool operator==(const xieite::pos&, const xieite::pos&) = default;
	};
}

#endif

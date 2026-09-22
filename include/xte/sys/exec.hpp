#ifndef DETAIL_XTE_HEADER_SYS_EXEC
#	define DETAIL_XTE_HEADER_SYS_EXEC
#
#	include "../aggregate.hpp"
#	include "../io/file.hpp"
#	include "../string.hpp"
#	include "../string_view.hpp"

namespace xte {
	inline xte::aggregate<^^xte::string, "output", ^^int, "status"> exec(xte::string_view command) noexcept(false) {
		if (auto pipe = xte::file_pipe(command)) {
			return { pipe.read(), pipe.close() };
		} else {
			return { "", pipe.close() };
		}
	}
}

#endif

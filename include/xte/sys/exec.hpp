#ifndef DETAIL_XTE_HEADER_SYS_EXEC
#	define DETAIL_XTE_HEADER_SYS_EXEC
#
#	include "../data/string.hpp"
#	include "../data/string_view.hpp"
#	include "../io/file_mode.hpp"
#	include "../io/file_pipe.hpp"
#	include "../meta/define_struct.hpp"

namespace xte {
	inline xte::define_struct<{ ^^xte::string, "output" }, { ^^int, "status" }> exec(xte::string_view command) noexcept(false) {
		auto pipe = xte::file_pipe(command, xte::file_mode::read);
		return { pipe.read(), pipe.close() };
	}
}

#endif

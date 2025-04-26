#ifndef DETAIL_XIEITE_HEADER_SYS_EXEC
#	define DETAIL_XIEITE_HEADER_SYS_EXEC
#
#	include <string>
#	include "../io/file_pipe.hpp"
#	include "../io/read.hpp"
#	include "../sys/process_status.hpp"
#	include "../sys/process_result.hpp"

namespace xieite {
	inline xieite::process_result exec(const std::string& cmd) noexcept {
		auto pipe = xieite::file_pipe(cmd, "r");
		const std::string output = xieite::read(pipe.get());
		return xieite::process_result(output, xieite::process_status(pipe.close()));
	}
}

#endif

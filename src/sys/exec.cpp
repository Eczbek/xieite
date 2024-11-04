export module xieite:exec;

import std;
import :file_pipe;
import :proc_status;
import :proc_result;
import :read;

export namespace xieite {
	xieite::proc_result exec(std::string_view cmd) noexcept {
		auto pipe = xieite::file_pipe(cmd, "r");
		const std::string output = xieite::read(pipe.get());
		return xieite::proc_result(output, xieite::proc_status(pipe.close()));
	}
}

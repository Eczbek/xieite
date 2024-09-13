export module xieite:system.execute;

import std;
import :streams.Pipe;
import :streams.read;
import :system.Result;

export namespace xieite::system {
	xieite::system::Result execute(const std::string_view command) noexcept {
		xieite::streams::Pipe pipe = xieite::streams::Pipe(std::string(command), "r");
		const std::string output = xieite::streams::read(pipe.file());
		return xieite::system::Result(output, pipe.close());
	}
}

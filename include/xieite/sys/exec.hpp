#pragma once

#include <string>
#include <string_view>
#include "../io/file_pipe.hpp"
#include "../io/read.hpp"
#include "../sys/proc_status.hpp"
#include "../sys/proc_result.hpp"

namespace xieite {
	inline xieite::proc_result exec(std::string_view cmd) noexcept {
		auto pipe = xieite::file_pipe(cmd, "r");
		const std::string output = xieite::read(pipe.get());
		return xieite::proc_result(output, xieite::proc_status(pipe.close()));
	}
}

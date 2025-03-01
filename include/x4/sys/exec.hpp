#pragma once

#include <string>
#include "../io/filepipe.hpp"
#include "../io/rd.hpp"
#include "../sys/procstat.hpp"
#include "../sys/procresult.hpp"

namespace x4 {
	inline x4::procresult exec(const std::string& cmd) noexcept {
		auto pipe = x4::filepipe(cmd, "r");
		const std::string output = x4::rd(pipe.get());
		return x4::procresult(output, x4::procstat(pipe.close()));
	}
}

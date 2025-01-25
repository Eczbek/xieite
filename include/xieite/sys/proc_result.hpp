#pragma once

#include <string>

namespace xieite {
	struct proc_result {
		std::string output;
		int status = 0;
	};
}

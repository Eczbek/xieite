#ifndef DETAIL_XIEITE_HEADER_SYS_PROCESS_RESULT
#	define DETAIL_XIEITE_HEADER_SYS_PROCESS_RESULT
#
#	include <string>

namespace xieite {
	struct process_result {
		std::string output;
		int status = 0;
	};
}

#endif

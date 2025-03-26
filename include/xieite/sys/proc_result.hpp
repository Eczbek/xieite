#ifndef DETAIL_XIEITE_HEADER_SYS_PROC_RESULT
#	define DETAIL_XIEITE_HEADER_SYS_PROC_RESULT
#
#	include <string>

namespace xieite {
	struct proc_result {
		std::string output;
		int status = 0;
	};
}

#endif

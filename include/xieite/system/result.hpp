#ifndef XIEITE_HEADER_SYSTEM_RESULT
#	define XIEITE_HEADER_SYSTEM_RESULT

#	include <string>

namespace xieite::system {
	struct Result {
		std::string output;
		int status = 0;
	};
}

#endif

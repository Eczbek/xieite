#ifndef XIEITE_HEADER_STREAMS_PIPE
#	define XIEITE_HEADER_STREAMS_PIPE

#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <cstdio>
#		include <stdio.h>
#		include <string>

namespace xieite::streams {
	struct Pipe {
		std::FILE* const file;

		Pipe(const std::string& command, const std::string& mode) noexcept
		: file(::popen(command.c_str(), mode.c_str())) {}

		~Pipe() {
			::pclose(this->file);
		}
	};
}

#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <cstdio>
#		include <stdio.h>

namespace xieite::streams {
	struct Pipe {
		std::FILE* const file;

		Pipe(const std::string& command, const std::string& mode) noexcept
		: file(::_popen(command.c_str(), mode.c_str())) {}

		~Pipe() {
			::_pclose(this->file);
		}
	};
}

#	else
#		error "Platform not supported"
#	endif

#endif

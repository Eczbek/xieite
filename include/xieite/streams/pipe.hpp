#ifndef XIEITE_HEADER_STREAMS_PIPE
#	define XIEITE_HEADER_STREAMS_PIPE

#	include <cstdio>
#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX || XIEITE_PLATFORM_TYPE_WINDOWS
#		include <stdio.h>
#		include <string>
#	endif

namespace xieite::streams {
	struct Pipe {
	public:
#	if XIEITE_PLATFORM_TYPE_UNIX
		Pipe(const std::string& command, const std::string& mode) noexcept
		: pipe(::popen(command.c_str(), mode.c_str())) {}
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		Pipe(const std::string& command, const std::string& mode) noexcept
		: pipe(::_popen(command.c_str(), mode.c_str())) {}

		Pipe(const std::wstring& command, const std::wstring& mode) noexcept
		: pipe(::_wpopen(command.c_str(), mode.c_str())) {}
#	endif

#	if XIEITE_PLATFORM_TYPE_UNIX
		~Pipe() {
			::pclose(this->pipe);
		}
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		~Pipe() {
			::_pclose(this->pipe);
		}
#	endif

		[[nodiscard]] std::FILE* file() const noexcept {
			return this->pipe;
		}

#	if XIEITE_PLATFORM_TYPE_UNIX
		[[nodiscard]] int descriptor() const noexcept {
			return ::fileno(this->pipe);
		}
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		[[nodiscard]] int descriptor() const noexcept {
			return ::_fileno(this->pipe);
		}
#	endif

	private:
		std::FILE* pipe;
	};
}

#endif

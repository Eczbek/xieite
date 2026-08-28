#ifndef DETAIL_XTE_HEADER_IO_FILE_PIPE
#	define DETAIL_XTE_HEADER_IO_FILE_PIPE
#
#	include "../data/string_view.hpp"
#	include "../io/eof.hpp"
#	include "../io/file.hpp"
#	include "../io/file_mode.hpp"
#	include "../preproc/lift.hpp"
#	include "../preproc/platform.hpp"
#	include <cstdio>
#	include <stdio.h>

#	if XTE_PLATFORM_UNIX
#		include <sys/wait.h>
#	endif

namespace xte {
	struct file_pipe : xte::file {
	public:
		[[nodiscard]] explicit(false) file_pipe() noexcept = default;

		[[nodiscard]] file_pipe(std::FILE* stream, xte::file_mode mode) noexcept
		: xte::file(stream, mode) {}

		[[nodiscard]] file_pipe(xte::string_view command, xte::file_mode mode) noexcept(false) {
			this->open(command, mode);
		}

		bool open(xte::string_view command, xte::file_mode mode) noexcept(false) {
#	if XTE_PLATFORM_WINDOWS
			std::FILE* pipe = command.make_c_str_for(XTE_LIFT(::_popen), mode);
#	else
			std::FILE* pipe = command.make_c_str_for(XTE_LIFT(::popen), mode);
#	endif
			return (*this = xte::file_pipe(pipe, mode));
		}

		int close() noexcept {
			if (!*this) {
				return xte::eof;
			}
#	if XTE_PLATFORM_WINDOWS
			int status = ::_pclose(this->release());
#	else
			int status = ::pclose(this->release());
			if (WIFEXITED(status)) {
				return WEXITSTATUS(status);
			}
			if (WIFSIGNALED(status)) {
				return WTERMSIG(status);
			}
			if (WIFSTOPPED(status)) {
				return WSTOPSIG(status);
			}
#	endif
			return status;
		}

		bool reopen(xte::string_view command, xte::file_mode mode) noexcept(false) {
			return !this->close() && this->open(command, mode);
		}
	};
}

#endif

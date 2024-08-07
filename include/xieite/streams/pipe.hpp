#ifndef XIEITE_HEADER_STREAMS_PIPE
#	define XIEITE_HEADER_STREAMS_PIPE

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_TYPE_UNIX && !XIEITE_PLATFORM_TYPE_WINDOWS
#		error "Platform not supported"
#	endif

#	include <cstdio>
#	include <stdio.h>
#	include <string>
#	include "../system/clean_status.hpp"

namespace xieite::streams {
	struct Pipe {
	public:
		Pipe() noexcept
		: stream(nullptr) {}

		Pipe(const std::string& command, const std::string& mode) noexcept {
			this->open(command, mode);
		}
		
#	if XIEITE_PLATFORM_TYPE_WINDOWS
		Pipe(const std::wstring& command, const std::wstring& mode) noexcept {
			this->open(command, mode);
		}
#	endif

		~Pipe() {
			this->close();
		}

		void open(const std::string& command, const std::string& mode) noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
			this->stream = ::popen(command.c_str(), mode.c_str());
#	else
			this->stream = ::_popen(command.c_str(), mode.c_str());
#	endif
		}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		void open(const std::wstring& command, const std::wstring& mode) noexcept {
			this->stream = ::_wpopen(command.c_str(), mode.c_str());
		}
#	endif

		int close() noexcept {
			if (!this->stream) {
				return -1;
			}
#	if XIEITE_PLATFORM_TYPE_UNIX
			const int status = ::pclose(this->stream);
#	else
			const int status = ::_pclose(this->stream);
#	endif
			this->stream = nullptr;
			return xieite::system::cleanStatus(status);
		}

		[[nodiscard]] std::FILE* file() const noexcept {
			return this->stream;
		}

		[[nodiscard]] int descriptor() const noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
			return ::fileno(this->stream);
#	else
			return ::_fileno(this->stream);
#	endif
		}

	private:
		std::FILE* stream;
	};
}

#endif

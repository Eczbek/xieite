module;

#include <xieite/platform.hpp>

#if !XIEITE_PLATFORM_TYPE_UNIX && !XIEITE_PLATFORM_TYPE_WINDOWS
#	warning "unsupported platform"
#endif

export module xieite:streams.Pipe;

import std.compat;
import :system.cleanStatus;

export namespace xieite::streams {
	struct Pipe {
	public:
		Pipe() noexcept
		: stream(nullptr) {}

		Pipe(const std::string& command, const std::string& mode) noexcept {
			this->open(command, mode);
		}
		
#if XIEITE_PLATFORM_TYPE_WINDOWS
		Pipe(const std::wstring& command, const std::wstring& mode) noexcept {
			this->open(command, mode);
		}
#endif

		~Pipe() {
			this->close();
		}

		void open(const std::string& command, const std::string& mode) noexcept {
#if XIEITE_PLATFORM_TYPE_WINDOWS
			this->stream = ::_popen(command.c_str(), mode.c_str());
#else
			this->stream = ::popen(command.c_str(), mode.c_str());
#endif
		}

#if XIEITE_PLATFORM_TYPE_WINDOWS
		void open(const std::wstring& command, const std::wstring& mode) noexcept {
			this->stream = ::_wpopen(command.c_str(), mode.c_str());
		}
#endif

		int close() noexcept {
			if (!this->stream) {
				return -1;
			}
#if XIEITE_PLATFORM_TYPE_WINDOWS
			const int status = ::_pclose(this->stream);
#else
			const int status = ::pclose(this->stream);
#endif
			this->stream = nullptr;
			return xieite::system::cleanStatus(status);
		}

		[[nodiscard]] std::FILE* file() const noexcept {
			return this->stream;
		}

		[[nodiscard]] int descriptor() const noexcept {
#if XIEITE_PLATFORM_TYPE_WINDOWS
			return ::_fileno(this->stream);
#else
			return ::fileno(this->stream);
#endif
		}

	private:
		std::FILE* stream;
	};
}

module;

#include <xieite/pltf.hpp>

#if !XIEITE_PLTF_TYPE_UNIX && !XIEITE_PLTF_TYPE_WINDOWS
#	warning "unsupported platform"
#endif

export module xieite:file_pipe;

import std.compat;
import :proc_status;

export namespace xieite {
	struct file_pipe {
	public:
		[[nodiscard]] file_pipe() noexcept : stream(nullptr) {}

		[[nodiscard]] file_pipe(std::string_view cmd, std::string_view mode) noexcept {
			this->open(cmd, mode);
		}
		
#if XIEITE_PLTF_TYPE_WINDOWS
		[[nodiscard]] file_pipe(std::wstring_view cmd, std::wstring_view mode) noexcept {
			this->open(cmd, mode);
		}
#endif

		~file_pipe() {
			this->close();
		}

		void open(std::string_view cmd, std::string_view mode) noexcept {
#if XIEITE_PLTF_TYPE_WINDOWS
			this->stream = ::_popen(std::string(cmd).c_str(), std::string(mode).c_str());
#else
			this->stream = ::popen(std::string(cmd).c_str(), std::string(mode).c_str());
#endif
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		void open(std::wstring_view cmd, std::wstring_view mode) noexcept {
			this->stream = ::_wpopen(std::wstring(cmd).c_str(), std::wstring(mode).c_str());
		}
#endif

		int close() noexcept {
			if (!this->stream) {
				return EOF;
			}
#if XIEITE_PLTF_TYPE_WINDOWS
			const int status = ::_pclose(this->stream);
#else
			const int status = ::pclose(this->stream);
#endif
			this->stream = nullptr;
			return xieite::proc_status(status);
		}

		[[nodiscard]] std::FILE* get() const noexcept {
			return this->stream;
		}

		[[nodiscard]] int descriptor() const noexcept {
#if XIEITE_PLTF_TYPE_WINDOWS
			return ::_fileno(this->stream);
#else
			return ::fileno(this->stream);
#endif
		}

	private:
		std::FILE* stream;
	};
}

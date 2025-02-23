#pragma once

#include <cstdio>
#include <stdio.h>
#include <string>
#include "../pp/pltf.hpp"
#include "../sys/proc_status.hpp"

#if !XIEITE_PLTF_TYPE_UNIX && !XIEITE_PLTF_TYPE_WINDOWS
#	warning "unsupported platform"
#endif

namespace xieite {
	struct file_pipe {
	public:
		[[nodiscard]] file_pipe() noexcept : stream(nullptr) {}

		[[nodiscard]] file_pipe(const std::string& cmd, const std::string& mode) noexcept {
			this->open(cmd, mode);
		}
		
#if XIEITE_PLTF_TYPE_WINDOWS
		[[nodiscard]] file_pipe(const std::wstring& cmd, const std::wstring& mode) noexcept {
			this->open(cmd, mode);
		}
#endif

		~file_pipe() {
			this->close();
		}

		void open(const std::string& cmd, const std::string& mode) noexcept {
#if XIEITE_PLTF_TYPE_WINDOWS
			this->stream = ::_popen(cmd.c_str(), mode.c_str());
#else
			this->stream = ::popen(cmd.c_str(), mode.c_str());
#endif
		}

#if XIEITE_PLTF_TYPE_WINDOWS
		void open(const std::wstring& cmd, const std::wstring& mode) noexcept {
			this->stream = ::_wpopen(cmd.c_str(), mode.c_str());
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

		[[nodiscard]] int desc() const noexcept {
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

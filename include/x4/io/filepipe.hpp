#pragma once

#include <cstdio>
#include <stdio.h>
#include <string>
#include "../pp/pltf.hpp"
#include "../sys/procstat.hpp"

#if !X4PLTF_UNIX && !X4PLTF_WINDOWS
#	warning "unsupported platform"
#endif

namespace x4 {
	struct filepipe {
	public:
		[[nodiscard]] filepipe() noexcept : stream(nullptr) {}

		[[nodiscard]] filepipe(const std::string& cmd, const std::string& mode) noexcept {
			this->open(cmd, mode);
		}
		
#if X4PLTF_WINDOWS
		[[nodiscard]] filepipe(const std::wstring& cmd, const std::wstring& mode) noexcept {
			this->open(cmd, mode);
		}
#endif

		~filepipe() {
			this->close();
		}

		[[nodiscard]] explicit(false) operator bool() const noexcept {
			return this->stream;
		}

		void open(const std::string& cmd, const std::string& mode) noexcept {
#if X4PLTF_WINDOWS
			this->stream = ::_popen(cmd.c_str(), mode.c_str());
#else
			this->stream = ::popen(cmd.c_str(), mode.c_str());
#endif
		}

#if X4PLTF_WINDOWS
		void open(const std::wstring& cmd, const std::wstring& mode) noexcept {
			this->stream = ::_wpopen(cmd.c_str(), mode.c_str());
		}
#endif

		int close() noexcept {
			if (!this->stream) {
				return EOF;
			}
#if X4PLTF_WINDOWS
			const int status = ::_pclose(this->stream);
#else
			const int status = ::pclose(this->stream);
#endif
			this->stream = nullptr;
			return x4::procstat(status);
		}

		[[nodiscard]] std::FILE* get() const noexcept {
			return this->stream;
		}

		[[nodiscard]] int desc() const noexcept {
#if X4PLTF_WINDOWS
			return ::_fileno(this->stream);
#else
			return ::fileno(this->stream);
#endif
		}

	private:
		std::FILE* stream;
	};
}

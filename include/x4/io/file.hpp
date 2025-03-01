#pragma once

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>
#include "../pp/cplr.hpp"
#include "../pp/pltf.hpp"
#include "../trait/isistream.hpp"
#include "../trait/isostream.hpp"
#include "../trait/isstream.hpp"

#if X4PLTF_UNIX
#	include <fcntl.h>
#	include <unistd.h>
#elif !X4PLTF_WINDOWS
#	warning "unsupported platform"
#endif

#if X4CPLR_GCC
#	include <ext/stdio_filebuf.h>
#endif

namespace x4 {
	struct file {
	public:
		[[nodiscard]] file(std::FILE* const stream = nullptr) noexcept
		: stream(stream) {}

		[[nodiscard]] file(const std::string& path, const std::string& mode) noexcept {
			this->open(path, mode);
		}

#if X4PLTF_WINDOWS
		[[nodiscard]] file(const std::wstring& path, const std::wstring& mode) noexcept {
			this->open(path, mode);
		}
#endif

		[[nodiscard]] file(int desc, const std::string& mode) noexcept {
			this->open(desc, mode);
		}

#if X4PLTF_WINDOWS
		[[nodiscard]] file(int desc, const std::wstring& mode) noexcept {
			this->open(desc, mode);
		}
#endif

		template<x4::isstream Stream>
		[[nodiscard]] file(Stream& stream) noexcept {
			this->open(stream);
		}

		[[nodiscard]] file(const std::string& path, const std::string& mode, x4::file other) noexcept {
			this->reopen(path, mode, other);
		}

#if X4PLTF_WINDOWS
		[[nodiscard]] file(const std::wstring& path, const std::wstring& mode, x4::file other) noexcept {
			this->reopen(path, mode, other);
		}
#endif

		~file() {
			this->close();
		}

		[[nodiscard]] explicit(false) operator bool() const noexcept {
			return this->stream;
		}

		void open(const std::string& path, const std::string& mode) noexcept {
			this->stream = std::fopen(path.c_str(), mode.c_str());
		}

#if X4PLTF_WINDOWS
		void open(const std::wstring& path, const std::wstring& mode) noexcept {
			this->stream = ::_wfopen(path.c_str(), mode.c_str());
		}
#endif

		

		void open(int desc, const std::string& mode) noexcept {
#if X4PLTF_WINDOWS
			this->stream = ::_fdopen(desc, mode.c_str());
#else
			this->stream = ::fdopen(desc, mode.c_str());
#endif
		}

#if X4PLTF_WINDOWS
		void open(int desc, const std::wstring& mode) noexcept {
			this->stream = ::_wfdopen(desc, mode.c_str());
		}
#endif

		template<x4::isstream Stream>
		void open(Stream& stream) noexcept {
			this->stream = ([&stream] -> std::FILE* {
				const Stream* ptr = std::addressof(stream);
				if constexpr (x4::isistream<Stream>) {
					if (ptr == std::addressof(std::cin)) {
						return stdin;
					}
				} else if constexpr (x4::isostream<Stream>) {
					if (ptr == std::addressof(std::cout)) {
						return stdout;
					}
					if ((ptr == std::addressof(std::cerr)) || (ptr == std::addressof(std::clog))) {
						return stderr;
					}
				}
				if constexpr (requires { stream.native_handle(); }) {
					const typename Stream::native_handle_type desc = stream.native_handle();
					std::string mode;
					mode.reserve(3);
					if constexpr (x4::isistream<Stream>) {
						mode += "r";
					}
					if constexpr (x4::isostream<Stream>) {
						mode += "w";
					}
#if X4PLTF_UNIX
					if (::fcntl(desc, F_GETFL) & O_APPEND) {
						mode += "a";
					}
#endif
					return file(desc, mode).release();
				} else {
#if X4CPLR_GCC
					return static_cast<__gnu_cxx::stdio_filebuf<typename Stream::char_type, typename Stream::traits_type>*>(stream.rdbuf())->file();
#else
					return nullptr;
#endif
				}
			})();
		}

		void reopen(const std::string& path, const std::string& mode, x4::file other) noexcept {
			this->stream = std::freopen(path.c_str(), mode.c_str(), other.get());
		}

#if X4PLTF_WINDOWS
		void reopen(const std::wstring& path, const std::wstring& mode, x4::file other) noexcept {
			this->stream = ::_wfreopen(path.c_str(), mode.c_str(), other.get());
		}
#endif

		int close() noexcept {
			if (this->stream && (this->stream != stdin) && (this->stream != stdout) && (this->stream != stderr)) {
				return std::fclose(this->release());
			}
			return EOF;
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

		[[nodiscard]] std::FILE* release() noexcept {
			std::FILE* const copy = this->stream;
			this->stream = nullptr;
			return copy;
		}

	private:
		std::FILE* stream;
	};
}

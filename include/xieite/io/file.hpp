#pragma once

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>
#include "../pp/compiler.hpp"
#include "../pp/platform.hpp"
#include "../trait/is_istream.hpp"
#include "../trait/is_ostream.hpp"
#include "../trait/is_stream.hpp"

#if XIEITE_PLATFORM_TYPE_UNIX
#	include <fcntl.h>
#	include <unistd.h>
#elif !XIEITE_PLATFORM_TYPE_WINDOWS
#	warning "unsupported platform"
#endif

#if XIEITE_COMPILER_TYPE_GCC
#	include <ext/stdio_filebuf.h>
#endif

namespace xieite {
	struct file {
	public:
		[[nodiscard]] file(std::FILE* const stream = nullptr) noexcept
		: stream(stream) {}

		[[nodiscard]] file(const std::string& path, const std::string& mode) noexcept {
			this->open(path, mode);
		}

#if XIEITE_PLATFORM_TYPE_WINDOWS
		[[nodiscard]] file(const std::wstring& path, const std::wstring& mode) noexcept {
			this->open(path, mode);
		}
#endif

		[[nodiscard]] file(int desc, const std::string& mode) noexcept {
			this->open(desc, mode);
		}

#if XIEITE_PLATFORM_TYPE_WINDOWS
		[[nodiscard]] file(int desc, const std::wstring& mode) noexcept {
			this->open(desc, mode);
		}
#endif

		template<xieite::is_stream Stream>
		[[nodiscard]] file(Stream& stream) noexcept {
			this->open(stream);
		}

		[[nodiscard]] file(const std::string& path, const std::string& mode, xieite::file other) noexcept {
			this->reopen(path, mode, other);
		}

#if XIEITE_PLATFORM_TYPE_WINDOWS
		[[nodiscard]] file(const std::wstring& path, const std::wstring& mode, xieite::file other) noexcept {
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

#if XIEITE_PLATFORM_TYPE_WINDOWS
		void open(const std::wstring& path, const std::wstring& mode) noexcept {
			this->stream = ::_wfopen(path.c_str(), mode.c_str());
		}
#endif

		

		void open(int desc, const std::string& mode) noexcept {
#if XIEITE_PLATFORM_TYPE_WINDOWS
			this->stream = ::_fdopen(desc, mode.c_str());
#else
			this->stream = ::fdopen(desc, mode.c_str());
#endif
		}

#if XIEITE_PLATFORM_TYPE_WINDOWS
		void open(int desc, const std::wstring& mode) noexcept {
			this->stream = ::_wfdopen(desc, mode.c_str());
		}
#endif

		template<xieite::is_stream Stream>
		void open(Stream& stream) noexcept {
			this->stream = ([&stream] -> std::FILE* {
				const Stream* ptr = std::addressof(stream);
				if constexpr (xieite::is_istream<Stream>) {
					if (ptr == std::addressof(std::cin)) {
						return stdin;
					}
				} else if constexpr (xieite::is_ostream<Stream>) {
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
					if constexpr (xieite::is_istream<Stream>) {
						mode += "r";
					}
					if constexpr (xieite::is_ostream<Stream>) {
						mode += "w";
					}
#if XIEITE_PLATFORM_TYPE_UNIX
					if (::fcntl(desc, F_GETFL) & O_APPEND) {
						mode += "a";
					}
#endif
					return file(desc, mode).release();
				} else {
#if XIEITE_COMPILER_TYPE_GCC
					return static_cast<__gnu_cxx::stdio_filebuf<typename Stream::char_type, typename Stream::traits_type>*>(stream.rdbuf())->file();
#else
					return nullptr;
#endif
				}
			})();
		}

		void reopen(const std::string& path, const std::string& mode, xieite::file other) noexcept {
			this->stream = std::freopen(path.c_str(), mode.c_str(), other.get());
		}

#if XIEITE_PLATFORM_TYPE_WINDOWS
		void reopen(const std::wstring& path, const std::wstring& mode, xieite::file other) noexcept {
			this->stream = ::_wfreopen(path.c_str(), mode.c_str(), other.get());
		}
#endif

		int close() noexcept {
			if (this->stream && (this->stream != stdin) && (this->stream != stdout) && (this->stream != stderr)) {
				return std::fclose(this->release());
			}
			return EOF; // Erroneous value
		}

		[[nodiscard]] std::FILE* get() const noexcept {
			return this->stream;
		}

		[[nodiscard]] int desc() const noexcept {
#if XIEITE_PLATFORM_TYPE_WINDOWS
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

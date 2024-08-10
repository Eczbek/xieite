#ifndef XIEITE_HEADER_STREAMS_FILE
#	define XIEITE_HEADER_STREAMS_FILE

#	include "../macros/platform.hpp"

#	if !XIEITE_PLATFORM_TYPE_UNIX && !XIEITE_PLATFORM_TYPE_WINDOWS
#		warning "Platform not supported"
#	endif

#	include <concepts>
#	include <cstdio>
#	include <iostream>
#	include <stdio.h>
#	include <string>
#	include "../concepts/input_stream.hpp"
#	include "../concepts/output_stream.hpp"
#	include "../concepts/stream.hpp"
#	include "../macros/compiler.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <fcntl.h>
#		include <unistd.h>
#	endif

#	if XIEITE_COMPILER_TYPE_GCC
#		include <ext/stdio_filebuf.h>
#	endif

namespace xieite::streams {
	struct File {
	public:
		File(std::FILE* const stream = nullptr) noexcept
		: stream(stream) {}

		File(const std::string& path, const std::string& mode) noexcept {
			this->open(path, mode);
		}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		File(const std::wstring& path, const std::wstring& mode) noexcept {
			this->open(path, mode);
		}
#	endif

		File(const int descriptor, const std::string& mode) noexcept {
			this->open(descriptor, mode);
		}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		File(const int descriptor, const std::wstring& mode) noexcept {
			this->open(descriptor, mode);
		}
#	endif

		template<xieite::concepts::Stream Stream_>
		File(Stream_& stream) noexcept {
			this->open(stream);
		}

		File(const std::string& path, const std::string& mode, const xieite::streams::File other) noexcept {
			this->reopen(path, mode, other);
		}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		File(const std::wstring& path, const std::wstring& mode, const xieite::streams::File other) noexcept {
			this->reopen(path, mode, other);
		}
#	endif

		~File() {
			this->close();
		}

		void open(const std::string& path, const std::string& mode) noexcept {
			this->stream = std::fopen(path.c_str(), mode.c_str());
		}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		void open(const std::wstring& path, const std::wstring& mode) noexcept {
			this->stream = ::_wfopen(path.c_str(), mode.c_str());
		}
#	endif

		void open(const int descriptor, const std::string& mode) noexcept {
#	if XIEITE_PLATFORM_TYPE_UNIX
			this->stream = ::fdopen(descriptor, mode.c_str());
#	else
			this->stream = ::_fdopen(descriptor, mode.c_str());
#	endif
		}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		void open(const int descriptor, const std::wstring& mode) noexcept {
			this->stream = ::_wfdopen(descriptor, mode.c_str());
		}
#	endif

		template<xieite::concepts::Stream Stream_>
		void open(Stream_& stream) noexcept {
			this->stream = ([&stream] {
				static constexpr bool isInput = xieite::concepts::InputStream<Stream_>;
				static constexpr bool isOutput = xieite::concepts::OutputStream<Stream_>;
				if constexpr (isInput) {
					if (&stream == &std::cin) {
						return stdin;
					}
				} else if constexpr (isOutput) {
					if (&stream == &std::cout) {
						return stdout;
					}
					if ((&stream == &std::cerr) || (&stream == &std::clog)) {
						return stderr;
					}
				}
				if constexpr (requires {
					stream.native_handle();
				}) {
					const typename Stream_::native_handle_type descriptor = stream.native_handle();
					std::string mode;
					mode.reserve(3);
					if constexpr (isInput) {
						mode += 'r';
					}
					if constexpr (isOutput) {
						mode += 'w';
					}
#	if XIEITE_PLATFORM_TYPE_UNIX
					if (::fcntl(descriptor, F_GETFL) & O_APPEND) {
						mode += 'a';
					}
#	endif
					xieite::streams::File file = xieite::streams::File(descriptor, mode);
					const std::FILE* result = file.stream;
					file.stream = nullptr;
					return result;
				} else {
#	if XIEITE_COMPILER_TYPE_GCC
					return static_cast<__gnu_cxx::stdio_filebuf<typename Stream_::char_type, typename Stream_::traits_type>*>(stream.rdbuf())->file();
#	else
					return nullptr;
#	endif
				}
			})();
		}

		void reopen(const std::string& path, const std::string& mode, const xieite::streams::File other) noexcept {
			this->stream = std::freopen(path.c_str(), mode.c_str(), other.file());
		}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		void reopen(const std::wstring& path, const std::wstring& mode, const xieite::streams::File other) noexcept {
			this->stream = ::_wfreopen(path.c_str(), mode.c_str(), other.file());
		}
#	endif

		void close() noexcept {
			if (this->stream && (this->stream != stdin) && (this->stream != stdout) && (this->stream != stderr)) {
				return std::fclose(this->stream);
			}
			return EOF; // Erroneous value of `std::fclose`
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

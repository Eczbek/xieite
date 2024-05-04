#ifndef XIEITE_HEADER_STREAMS_FILE
#	define XIEITE_HEADER_STREAMS_FILE

#	include <concepts>
#	include <cstdio>
#	include <iostream>
#	include <string>
#	include "../concepts/input_stream.hpp"
#	include "../concepts/output_stream.hpp"
#	include "../concepts/stream.hpp"
#	include "../macros/compiler.hpp"
#	include "../macros/platform.hpp"

#	if XIEITE_PLATFORM_TYPE_UNIX
#		include <fcntl.h>
#		include <stdio.h>
#		include <unistd.h>
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
#		include <stdio.h>
#	endif

#	if XIEITE_COMPILER_TYPE_GCC
#		include <ext/stdio_filebuf.h>
#	endif

namespace xieite::streams {
	struct File {
	public:
		File(std::FILE* const stream = nullptr) noexcept
		: stream(stream) {}

		File(const std::string& path, const std::string& mode) noexcept
		: stream(std::fopen(path.c_str(), mode.c_str())) {}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		File(const std::wstring& path, const std::wstring& mode) noexcept
		: stream(::_wfopen(path.c_str(), mode.c_str())) {}
#	endif

		File(const std::string& path, const std::string& mode, const xieite::streams::File other) noexcept
		: stream(std::freopen(path.c_str(), mode.c_str(), other.file())) {}

#	if XIEITE_PLATFORM_TYPE_WINDOWS
		File(const std::wstring& path, const std::wstring& mode, const xieite::streams::File other) noexcept
		: stream(::_wfreopen(path.c_str(), mode.c_str(), other.file())) {}
#	endif

#	if XIEITE_PLATFORM_TYPE_UNIX
		File(const int descriptor, const std::string& mode) noexcept
		: stream(::fdopen(descriptor, mode.c_str())) {}
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		File(const int descriptor, const std::string& mode) noexcept
		: stream(::_fdopen(descriptor, mode.c_str())) {}

		File(const int descriptor, const std::wstring& mode) noexcept
		: stream(::_wfdopen(descriptor, mode.c_str())) {}
#	endif

		template<xieite::concepts::Stream Stream_>
		File(const Stream_& stream) noexcept
		: stream(([&stream] {
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
				{ stream.native_handle() } -> std::same_as<typename Stream_::native_handle_type>;
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
				return xieite::streams::File(descriptor, mode);
			} else {
#	if XIEITE_COMPILER_TYPE_GCC
				return static_cast<__gnu_cxx::stdio_filebuf<typename Stream_::char_type, typename Stream_::traits_type>*>(stream.rdbuf())->file();
#	else
				return nullptr;
#	endif
			}
		})()) {}

		~File() {
			if ((this->stream != stdin) && (this->stream != stdout) && (this->stream != stderr)) {
				std::fclose(this->stream);
			}
		}

		[[nodiscard]] std::FILE* file() const noexcept {
			return this->stream;
		}

#	if XIEITE_PLATFORM_TYPE_UNIX
		[[nodiscard]] int descriptor() const noexcept {
			return ::fileno(this->stream);
		}
#	elif XIEITE_PLATFORM_TYPE_WINDOWS
		[[nodiscard]] int descriptor() const noexcept {
			return ::_fileno(this->stream);
		}
#	endif

	private:
		std::FILE* stream;
	};
}

#endif

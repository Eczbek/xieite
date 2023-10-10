#ifndef XIEITE_HEADER__STREAMS__GET_FILE
#	define XIEITE_HEADER__STREAMS__GET_FILE

#	include "../macros/compiler_type.hpp"

#	if !XIEITE__COMPILER_TYPE__GCC
#		error "Compiler not supported"
#	endif

#	include <cstdio>
#	include <ext/stdio_filebuf.h>
#	include <iostream>
#	include "../concepts/input_stream.hpp"
#	include "../concepts/output_stream.hpp"
#	include "../concepts/stream.hpp"

namespace xieite::streams {
	template<xieite::concepts::Stream Stream>
	[[nodiscard]] inline std::FILE* getFile(const Stream& stream) noexcept {
		if constexpr (xieite::concepts::InputStream<Stream>) {
			if (&stream == &std::cin) {
				return stdin;
			}
		}
		if constexpr (xieite::concepts::OutputStream<Stream>) {
			if (&stream == &std::cout) {
				return stdout;
			}
			if ((&stream == &std::cerr) || (&stream == &std::clog)) {
				return stderr;
			}
		}
		return static_cast<__gnu_cxx::stdio_filebuf<typename Stream::char_type, typename Stream::traits_type>*>(stream.rdbuf())->file();
	}
}

#endif

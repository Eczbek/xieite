#ifndef XIEITE_HEADER__SYSTEM__GET_STREAM_FILE
#	define XIEITE_HEADER__SYSTEM__GET_STREAM_FILE

#	include "../macros/COMPILER_TYPE.hpp"

#	if !XIEITE__COMPILER_TYPE__GCC
#		error "Compiler not supported"
#	endif

#	include <concepts>
#	include <cstdio>
#	include <ext/stdio_filebuf.h>
#	include <fstream>
#	include <iostream>
#	include <istream>
#	include <ostream>

namespace xieite::system {
	template<typename Stream>
	requires(std::same_as<Stream, std::istream> || std::derived_from<Stream, std::istream> || std::same_as<Stream, std::ostream> || std::derived_from<Stream, std::ostream>)
	[[nodiscard]]
	inline std::FILE* getStreamFile(const Stream& stream) noexcept {
		if constexpr (std::same_as<Stream, std::istream> || std::derived_from<Stream, std::istream>) {
			if (&stream == &std::cin) {
				return stdin;
			}
		}
		if constexpr (std::same_as<Stream, std::ostream> || std::derived_from<Stream, std::ostream>) {
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

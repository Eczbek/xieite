#ifndef XIEITE_HEADER_SYSTEM_GETSTREAMFILE
#	define XIEITE_HEADER_SYSTEM_GETSTREAMFILE

#	include "../macros/COMPILER_TYPE.hpp"

#	if !XIEITE_COMPILER_TYPE_GCC
#		error "Compiler not supported"
#	endif

#	include <cstdio>
#	include <ext/stdio_filebuf.h>
#	include <fstream>
#	include <iostream>
#	include <istream>
#	include <ostream>
#	include "../concepts/SameAsOrDerivedFrom.hpp"

namespace xieite::system {
	template<xieite::concepts::SameAsOrDerivedFrom<std::istream, std::ostream> Stream>
	[[nodiscard]]
	inline std::FILE* getStreamFile(const Stream& stream) noexcept {
		if constexpr (xieite::concepts::SameAsOrDerivedFrom<Stream, std::istream>) {
			if (&stream == &std::cin) {
				return stdin;
			}
		}
		if constexpr (xieite::concepts::SameAsOrDerivedFrom<Stream, std::ostream>) {
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

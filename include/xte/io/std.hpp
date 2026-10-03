#ifndef DETAIL_XTE_HEADER_IO_STD
#	define DETAIL_XTE_HEADER_IO_STD
#
#	include "../io/file.hpp"
#	include <cstdio>

namespace xte::std {
	xte::file const inline in = xte::file(stdin, xte::file_mode::read);

	xte::file const inline out = xte::file(stdout, xte::file_mode::write);

	xte::file const inline err = xte::file(stderr, xte::file_mode::write);
}

#endif

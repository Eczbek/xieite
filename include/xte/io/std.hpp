#ifndef DETAIL_XTE_HEADER_IO_STD
#	define DETAIL_XTE_HEADER_IO_STD
#
#	include "../io/file.hpp"
#	include <cstdio>

namespace xte::std {
	inline const xte::file in = xte::file(stdin, xte::file::mode::read);

	inline const xte::file out = xte::file(stdout, xte::file::mode::write);

	inline const xte::file err = xte::file(stderr, xte::file::mode::write);
}

#endif

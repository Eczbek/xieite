#ifndef DETAIL_XIEITE_HEADER_PP_CASES
#	define DETAIL_XIEITE_HEADER_PP_CASES
#
#	include "../pp/each.hpp"
#
#	define XIEITE_CASES(...) XIEITE_EACH_DELIM(case, :, __VA_ARGS__)
#endif

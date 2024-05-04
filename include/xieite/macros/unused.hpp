#ifndef XIEITE_HEADER_MACROS_UNUSED
#	define XIEITE_HEADER_MACROS_UNUSED

#	define XIEITE_UNUSED(...) __VA_OPT__(static_cast<void>(__VA_ARGS__))

#endif

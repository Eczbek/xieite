#ifndef XIEITE_HEADER_MACROS_FORWARD
#	define XIEITE_HEADER_MACROS_FORWARD

#	include <utility>

#	define XIEITE_FORWARD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

#endif

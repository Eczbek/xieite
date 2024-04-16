#ifndef XIEITE_HEADER_MACROS_FORWARD
#	define XIEITE_HEADER_MACROS_FORWARD

#	define XIEITE_FORWARD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__) // static_cast is slightly faster than std::forward on major compilers

#endif

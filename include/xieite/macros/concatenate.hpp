#ifndef XIEITE_HEADER_MACROS_CONCATENATE
#	define XIEITE_HEADER_MACROS_CONCATENATE

#	define XIEITE_CONCATENATE(first, second) first##second

#	define XIEITE_CONCATENATE_REVERSE(first, second) second##first

#	define XIEITE_CONCATENATE_SCAN(first, second) CONCATENATE(first, second)

#	define XIEITE_CONCATENATE_SCAN_FIRST(first) CONCATENATE(first,

#	define XIEITE_CONCATENATE_SCAN_SECOND(second) CONCATENATE_REVERSE(second,

#endif

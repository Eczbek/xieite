#ifndef XIEITE_HEADER__MACROS__CONCATENATE
#	define XIEITE_HEADER__MACROS__CONCATENATE

#	define XIEITE__CONCATENATE(first, second) XIEITE_INTERNAL_CONCATENATE(first, second)

#	define XIEITE_INTERNAL_CONCATENATE(first, second) first ## second

#endif

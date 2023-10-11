#ifndef XIEITE_HEADER_MACROS_NO_RETURN
#	define XIEITE_HEADER_MACROS_NO_RETURN

#	if defined(__cplusplus) || defined(__has_c_attribute) && __has_c_attribute(noreturn)
#		define XIEITE_NO_RETURN [[noreturn]]
#	else
#		define XIEITE_NO_RETURN _Noreturn
#	endif

#endif

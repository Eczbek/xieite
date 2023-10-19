#ifndef XIEITE_HEADER_MACROS_NO_RETURN
#	define XIEITE_HEADER_MACROS_NO_RETURN

#	if defined(__cplusplus)
#		define XIEITE_NO_RETURN [[noreturn]]
#	elif defined(__has_c_attribute)
#		if __has_c_attribute(noreturn)
#			define XIEITE_NO_RETURN [[noreturn]]
#		endif
#	else
#		define XIEITE_NO_RETURN _Noreturn
#	endif

#endif

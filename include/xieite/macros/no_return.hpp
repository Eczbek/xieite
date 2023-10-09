#ifndef XIEITE_HEADER__MACROS__NO_RETURN
#	define XIEITE_HEADER__MACROS__NO_RETURN

#	if defined(__cplusplus) || defined(__has_c_attribute) && __has_c_attribute(noreturn)
#		define XIEITE__NO_RETURN [[noreturn]]
#	else
#		define XIEITE__NO_RETURN _Noreturn
#	endif

#endif

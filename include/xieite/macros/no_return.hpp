#ifndef XIEITE_HEADER_MACROS_NO_RETURN
#	define XIEITE_HEADER_MACROS_NO_RETURN

#	include "../macros/language_standard.hpp"

#	if defined(__cplusplus) || XIEITE_LANGUAGE_STANDARD_C_2023
#		define XIEITE_NO_RETURN [[noreturn]]
#	else
#		define XIEITE_NO_RETURN _Noreturn
#	endif

#endif

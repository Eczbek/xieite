#pragma once

#if defined(__cplusplus) || defined(__has_c_attribute) && __has_c_attribute(noreturn)
#	define XIEITE_NO_RETURN [[noreturn]]
#else
#	define XIEITE_NO_RETURN _Noreturn
#endif

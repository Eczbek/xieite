#pragma once

#include <xieite/cplr.hpp>
#include <xieite/pragma.hpp>
#include <xieite/str.hpp>

#define XIEITE_DIAG_MSG(_)
#define XIEITE_DIAG_WARN(_)
#define XIEITE_DIAG_ERR(_)
#define XIEITE_DIAG_PUSH()
#define XIEITE_DIAG_POP()
#define XIEITE_DIAG_ON_GCC(_)
#define XIEITE_DIAG_ON_CLANG(_)
#define XIEITE_DIAG_ON_MSVC(_)
#define XIEITE_DIAG_STRICT_GCC(_)
#define XIEITE_DIAG_STRICT_CLANG(_)
#define XIEITE_DIAG_STRICT_MSVC(_)
#define XIEITE_DIAG_OFF_GCC(_)
#define XIEITE_DIAG_OFF_CLANG(_)
#define XIEITE_DIAG_OFF_MSVC(_)

#if XIEITE_CPLR_TYPE_GCC
#	undef XIEITE_DIAG_MSG
#	define XIEITE_DIAG_MSG(s) XIEITE_PRAGMA(message s)

#	undef XIEITE_DIAG_WARN
#	define XIEITE_DIAG_WARN(s) XIEITE_PRAGMA(GCC warning s)

#	undef XIEITE_DIAG_ERR
#	define XIEITE_DIAG_ERR(s) XIEITE_PRAGMA(GCC error s)

#	undef XIEITE_DIAG_PUSH
#	define XIEITE_DIAG_PUSH() XIEITE_PRAGMA(GCC diagnostic push)

#	undef XIEITE_DIAG_POP
#	define XIEITE_DIAG_POP() XIEITE_PRAGMA(GCC diagnostic pop)

#	undef XIEITE_DIAG_ON_GCC
#	define XIEITE_DIAG_ON_GCC(x) XIEITE_PRAGMA(GCC diagnostic warning XIEITE_STR(x))

#	undef XIEITE_DIAG_STRICT_GCC
#	define XIEITE_DIAG_STRICT_GCC(x) XIEITE_PRAGMA(GCC diagnostic error XIEITE_STR(x))

#	undef XIEITE_DIAG_OFF_GCC
#	define XIEITE_DIAG_OFF_GCC(x) XIEITE_PRAGMA(GCC diagnostic ignored XIEITE_STR(x))
#elif XIEITE_CPLR_TYPE_CLANG
#	undef XIEITE_DIAG_MSG
#	define XIEITE_DIAG_MSG(s) XIEITE_PRAGMA(message s)

#	undef XIEITE_DIAG_WARN
#	define XIEITE_DIAG_WARN(s) XIEITE_PRAGMA(GCC warning s)

#	undef XIEITE_DIAG_ERR
#	define XIEITE_DIAG_ERR(s) XIEITE_PRAGMA(GCC error s)

#	undef XIEITE_DIAG_PUSH
#	define XIEITE_DIAG_PUSH() XIEITE_PRAGMA(clang diagnostic push)

#	undef XIEITE_DIAG_POP
#	define XIEITE_DIAG_POP() XIEITE_PRAGMA(clang diagnostic pop)

#	undef XIEITE_DIAG_ON_CLANG
#	define XIEITE_DIAG_ON_CLANG(x) XIEITE_PRAGMA(clang diagnostic warning XIEITE_STR(x))

#	undef XIEITE_DIAG_STRICT_CLANG
#	define XIEITE_DIAG_STRICT_CLANG(x) XIEITE_PRAGMA(clang diagnostic error XIEITE_STR(x))

#	undef XIEITE_DIAG_OFF_CLANG
#	define XIEITE_DIAG_OFF_CLANG(x) XIEITE_PRAGMA(clang diagnostic ignored XIEITE_STR(x))
#elif XIEITE_CPLR_TYPE_MSVC
#	undef XIEITE_DIAG_MSG
#	define XIEITE_DIAG_MSG(s) XIEITE_PRAGMA(message(s))

#	undef XIEITE_DIAG_WARN
#	define XIEITE_DIAG_WARN(s) XIEITE_PRAGMA(message("\x1B[31m" s "\x1B[0m"))

#	undef XIEITE_DIAG_ERR
#	define XIEITE_DIAG_ERR(s) XIEITE_PRAGMA(message("\x1B[35m" s "\x1B[0m"))

#	undef XIEITE_DIAG_PUSH
#	define XIEITE_DIAG_PUSH() XIEITE_PRAGMA(warning(push))

#	undef XIEITE_DIAG_POP
#	define XIEITE_DIAG_POP() XIEITE_PRAGMA(warning(pop))

#	undef XIEITE_DIAG_ON_MSVC
#	define XIEITE_DIAG_ON_MSVC(x) XIEITE_PRAGMA(warning(default: x))

#	undef XIEITE_DIAG_STRICT_MSVC
#	define XIEITE_DIAG_STRICT_MSVC(x) XIEITE_PRAGMA(warning(error: x))

#	undef XIEITE_DIAG_OFF_MSVC
#	define XIEITE_DIAG_OFF_MSVC(x) XIEITE_PRAGMA(warning(disable: x))
#endif

// https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warnings-c4000-c5999

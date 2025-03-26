#ifndef DETAIL_XIEITE_HEADER_PP_DIAG
#	define DETAIL_XIEITE_HEADER_PP_DIAG
#
#	include "../pp/compiler.hpp"
#	include "../pp/pragma.hpp"
#
#	define XIEITE_DIAG_MSG(_)
#	define XIEITE_DIAG_MSG_GCC(_)
#	define XIEITE_DIAG_MSG_CLANG(_)
#	define XIEITE_DIAG_MSG_MSVC(_)
#	define XIEITE_DIAG_WARN(_)
#	define XIEITE_DIAG_WARN_GCC(_)
#	define XIEITE_DIAG_WARN_CLANG(_)
#	define XIEITE_DIAG_WARN_MSVC(_)
#	define XIEITE_DIAG_ERR(_)
#	define XIEITE_DIAG_ERR_GCC(_)
#	define XIEITE_DIAG_ERR_CLANG(_)
#	define XIEITE_DIAG_ERR_MSVC(_)
#	define XIEITE_DIAG_PUSH()
#	define XIEITE_DIAG_PUSH_GCC()
#	define XIEITE_DIAG_PUSH_CLANG()
#	define XIEITE_DIAG_PUSH_MSVC()
#	define XIEITE_DIAG_POP()
#	define XIEITE_DIAG_POP_GCC()
#	define XIEITE_DIAG_POP_CLANG()
#	define XIEITE_DIAG_POP_MSVC()
#	define XIEITE_DIAG_ON_GCC(_)
#	define XIEITE_DIAG_ON_CLANG(_)
#	define XIEITE_DIAG_ON_MSVC(_)
#	define XIEITE_DIAG_STRICT_GCC(_)
#	define XIEITE_DIAG_STRICT_CLANG(_)
#	define XIEITE_DIAG_STRICT_MSVC(_)
#	define XIEITE_DIAG_OFF_GCC(_)
#	define XIEITE_DIAG_OFF_CLANG(_)
#	define XIEITE_DIAG_OFF_MSVC(_)
#
#	if XIEITE_COMPILER_TYPE_GCC && !XIEITE_COMPILER_TYPE_CLANG
#		undef XIEITE_DIAG_MSG
#		define XIEITE_DIAG_MSG(s_) XIEITE_PRAGMA(message s_)
#
#		undef XIEITE_DIAG_MSG_GCC
#		define XIEITE_DIAG_MSG_GCC(s_) XIEITE_DIAG_MSG(s_)
#
#		undef XIEITE_DIAG_WARN
#		define XIEITE_DIAG_WARN(s_) XIEITE_PRAGMA(GCC warning s_)
#
#		undef XIEITE_DIAG_WARN_GCC
#		define XIEITE_DIAG_WARN_GCC(s_) XIEITE_DIAG_WARN(s_)
#
#		undef XIEITE_DIAG_ERR
#		define XIEITE_DIAG_ERR(s_) XIEITE_PRAGMA(GCC error s_)
#
#		undef XIEITE_DIAG_ERR_GCC
#		define XIEITE_DIAG_ERR_GCC(s_) XIEITE_DIAG_ERR(s_)
#
#		undef XIEITE_DIAG_PUSH
#		define XIEITE_DIAG_PUSH() XIEITE_PRAGMA(GCC diagnostic push)
#
#		undef XIEITE_DIAG_PUSH_GCC
#		define XIEITE_DIAG_PUSH_GCC() XIEITE_DIAG_PUSH()
#
#		undef XIEITE_DIAG_POP
#		define XIEITE_DIAG_POP() XIEITE_PRAGMA(GCC diagnostic pop)
#
#		undef XIEITE_DIAG_POP_GCC
#		define XIEITE_DIAG_POP_GCC() XIEITE_DIAG_POP()
#
#		undef XIEITE_DIAG_ON_GCC
#		define XIEITE_DIAG_ON_GCC(s_) XIEITE_PRAGMA(GCC diagnostic warning s_)
#
#		undef XIEITE_DIAG_STRICT_GCC
#		define XIEITE_DIAG_STRICT_GCC(s_) XIEITE_PRAGMA(GCC diagnostic error s_)
#
#		undef XIEITE_DIAG_OFF_GCC
#		define XIEITE_DIAG_OFF_GCC(s_) XIEITE_PRAGMA(GCC diagnostic ignored s_)
#	elif XIEITE_COMPILER_TYPE_CLANG
#		undef XIEITE_DIAG_MSG
#		define XIEITE_DIAG_MSG(s_) XIEITE_PRAGMA(message s_)
#
#		undef XIEITE_DIAG_MSG_CLANG
#		define XIEITE_DIAG_MSG_CLANG(s_) XIEITE_DIAG_MSG(s_)
#
#		undef XIEITE_DIAG_WARN
#		define XIEITE_DIAG_WARN(s_) XIEITE_PRAGMA(GCC warning s_)
#
#		undef XIEITE_DIAG_WARN_CLANG
#		define XIEITE_DIAG_WARN_CLANG(s_) XIEITE_DIAG_WARN(s_)
#
#		undef XIEITE_DIAG_ERR
#		define XIEITE_DIAG_ERR(s_) XIEITE_PRAGMA(GCC error s_)
#
#		undef XIEITE_DIAG_ERR_CLANG
#		define XIEITE_DIAG_ERR_CLANG(s_) XIEITE_DIAG_ERR(s_)
#
#		undef XIEITE_DIAG_PUSH
#		define XIEITE_DIAG_PUSH() XIEITE_PRAGMA(clang diagnostic push)
#
#		undef XIEITE_DIAG_PUSH_CLANG
#		define XIEITE_DIAG_PUSH_CLANG() XIEITE_DIAG_PUSH()
#
#		undef XIEITE_DIAG_POP
#		define XIEITE_DIAG_POP() XIEITE_PRAGMA(clang diagnostic pop)
#
#		undef XIEITE_DIAG_POP_CLANG
#		define XIEITE_DIAG_POP_CLANG() XIEITE_DIAG_POP()
#
#		undef XIEITE_DIAG_ON_CLANG
#		define XIEITE_DIAG_ON_CLANG(s_) XIEITE_PRAGMA(clang diagnostic warning s_)
#
#		undef XIEITE_DIAG_STRICT_CLANG
#		define XIEITE_DIAG_STRICT_CLANG(s_) XIEITE_PRAGMA(clang diagnostic error s_)
#
#		undef XIEITE_DIAG_OFF_CLANG
#		define XIEITE_DIAG_OFF_CLANG(s_) XIEITE_PRAGMA(clang diagnostic ignored s_)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		undef XIEITE_DIAG_MSG
#		define XIEITE_DIAG_MSG(s_) XIEITE_PRAGMA(message(s_))
#
#		undef XIEITE_DIAG_MSG_MSVC
#		define XIEITE_DIAG_MSG_MSVC(s_) XIEITE_DIAG_MSG(s_)
#
#		undef XIEITE_DIAG_WARN
#		define XIEITE_DIAG_WARN(s_) XIEITE_PRAGMA(message("\x1B[31m" s_ "\x1B[0m"))
#
#		undef XIEITE_DIAG_WARN_MSVC
#		define XIEITE_DIAG_WARN_MSVC(s_) XIEITE_DIAG_WARN(s_)
#
#		undef XIEITE_DIAG_ERR
#		define XIEITE_DIAG_ERR(s_) XIEITE_PRAGMA(message("\x1B[35m" s_ "\x1B[0m"))
#
#		undef XIEITE_DIAG_ERR_MSVC
#		define XIEITE_DIAG_ERR_MSVC(s_) XIEITE_DIAG_ERR(s_)
#
#		undef XIEITE_DIAG_PUSH
#		define XIEITE_DIAG_PUSH() XIEITE_PRAGMA(warning(push))
#
#		undef XIEITE_DIAG_PUSH_MSVC
#		define XIEITE_DIAG_PUSH_MSVC() XIEITE_DIAG_PUSH()
#
#		undef XIEITE_DIAG_POP
#		define XIEITE_DIAG_POP() XIEITE_PRAGMA(warning(pop))
#
#		undef XIEITE_DIAG_POP_MSVC
#		define XIEITE_DIAG_POP_MSVC() XIEITE_DIAG_POP()
#
#		undef XIEITE_DIAG_ON_MSVC
#		define XIEITE_DIAG_ON_MSVC(n_) XIEITE_PRAGMA(warning(default: n_))
#
#		undef XIEITE_DIAG_STRICT_MSVC
#		define XIEITE_DIAG_STRICT_MSVC(n_) XIEITE_PRAGMA(warning(error: n_))
#
#		undef XIEITE_DIAG_OFF_MSVC
#		define XIEITE_DIAG_OFF_MSVC(n_) XIEITE_PRAGMA(warning(disable: n_))
#	endif
#endif

// https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warnings-c4000-c5999

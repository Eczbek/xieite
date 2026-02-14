#ifndef DETAIL_XTE_HEADER_PREPROC_DIAGNOSTIC
#	define DETAIL_XTE_HEADER_PREPROC_DIAGNOSTIC
#
#	include "../preproc/any.hpp"
#	include "../preproc/compiler.hpp"
#	include "../preproc/if.hpp"
#	include "../preproc/pragma.hpp"
#
#	define XTE_DIAGNOSTIC_INFO(_string)
#	define XTE_DIAGNOSTIC_INFO_GCC(_string)
#	define XTE_DIAGNOSTIC_INFO_CLANG(_string)
#	define XTE_DIAGNOSTIC_INFO_MSVC(_string)
#	define XTE_DIAGNOSTIC_WARN(_string)
#	define XTE_DIAGNOSTIC_WARN_GCC(_string)
#	define XTE_DIAGNOSTIC_WARN_CLANG(_string)
#	define XTE_DIAGNOSTIC_WARN_MSVC(_string)
#	define XTE_DIAGNOSTIC_ERROR(_string)
#	define XTE_DIAGNOSTIC_ERROR_GCC(_string)
#	define XTE_DIAGNOSTIC_ERROR_CLANG(_string)
#	define XTE_DIAGNOSTIC_ERROR_MSVC(_string)
#	define XTE_DIAGNOSTIC_PUSH(_operation, ...)
#	define XTE_DIAGNOSTIC_PUSH_GCC(_operation, ...)
#	define XTE_DIAGNOSTIC_PUSH_CLANG(_operation, ...)
#	define XTE_DIAGNOSTIC_PUSH_MSVC(_operation, ...)
#	define XTE_DIAGNOSTIC_POP()
#	define XTE_DIAGNOSTIC_POP_GCC()
#	define XTE_DIAGNOSTIC_POP_CLANG()
#	define XTE_DIAGNOSTIC_POP_MSVC()
#	define XTE_DIAGNOSTIC_ON_GCC(_id, ...)
#	define XTE_DIAGNOSTIC_ON_CLANG(_id, ...)
#	define XTE_DIAGNOSTIC_ON_MSVC(_id, ...)
#	define XTE_DIAGNOSTIC_STRICT_GCC(_id, ...)
#	define XTE_DIAGNOSTIC_STRICT_CLANG(_id, ...)
#	define XTE_DIAGNOSTIC_STRICT_MSVC(_id, ...)
#	define XTE_DIAGNOSTIC_OFF_GCC(_id, ...)
#	define XTE_DIAGNOSTIC_OFF_CLANG(_id, ...)
#	define XTE_DIAGNOSTIC_OFF_MSVC(_id, ...)
#
#	define XTE_DIAGNOSTIC_INFO_GCC_CLANG(_string) \
		XTE_DIAGNOSTIC_INFO_GCC(_string) \
		XTE_DIAGNOSTIC_INFO_CLANG(_string)
#	define XTE_DIAGNOSTIC_WARN_GCC_CLANG(_string) \
		XTE_DIAGNOSTIC_WARN_GCC(_string) \
		XTE_DIAGNOSTIC_WARN_CLANG(_string)
#	define XTE_DIAGNOSTIC_ERROR_GCC_CLANG(_string) \
		XTE_DIAGNOSTIC_ERROR_GCC(_string) \
		XTE_DIAGNOSTIC_ERROR_CLANG(_string)
#	define XTE_DIAGNOSTIC_PUSH_GCC_CLANG(_operation, ...) \
		XTE_DIAGNOSTIC_PUSH_GCC(_operation, __VA_ARGS__) \
		XTE_DIAGNOSTIC_PUSH_CLANG(_operation, __VA_ARGS__)
#	define XTE_DIAGNOSTIC_PUSH_GCC_MSVC(_operation, ...) \
		XTE_DIAGNOSTIC_PUSH_GCC(_operation, __VA_ARGS__) \
		XTE_DIAGNOSTIC_PUSH_MSVC(_operation, __VA_ARGS__)
#	define XTE_DIAGNOSTIC_PUSH_CLANG_MSVC(_operation, ...) \
		XTE_DIAGNOSTIC_PUSH_CLANG(_operation, __VA_ARGS__) \
		XTE_DIAGNOSTIC_PUSH_MSVC(_operation, __VA_ARGS__)
#	define XTE_DIAGNOSTIC_POP_GCC_CLANG() \
		XTE_DIAGNOSTIC_POP_GCC() \
		XTE_DIAGNOSTIC_POP_CLANG()
#	define XTE_DIAGNOSTIC_POP_GCC_MSVC() \
		XTE_DIAGNOSTIC_POP_GCC() \
		XTE_DIAGNOSTIC_POP_MSVC()
#	define XTE_DIAGNOSTIC_POP_CLANG_MSVC() \
		XTE_DIAGNOSTIC_POP_CLANG() \
		XTE_DIAGNOSTIC_POP_MSVC()
#	define XTE_DIAGNOSTIC_ON_GCC_CLANG(_string) \
		XTE_DIAGNOSTIC_ON_GCC(_string) \
		XTE_DIAGNOSTIC_ON_CLANG(_string)
#	define XTE_DIAGNOSTIC_STRICT_GCC_CLANG(_string) \
		XTE_DIAGNOSTIC_STRICT_GCC(_string) \
		XTE_DIAGNOSTIC_STRICT_CLANG(_string)
#	define XTE_DIAGNOSTIC_OFF_GCC_CLANG(_string) \
		XTE_DIAGNOSTIC_OFF_GCC(_string) \
		XTE_DIAGNOSTIC_OFF_CLANG(_string)
#
#	if XTE_COMPILER_MSVC
#		undef XTE_DIAGNOSTIC_INFO
#		define XTE_DIAGNOSTIC_INFO(_string) XTE_DIAGNOSTIC_INFO_MSVC(_string)
#
#		undef XTE_DIAGNOSTIC_WARN
#		define XTE_DIAGNOSTIC_WARN(_string) XTE_DIAGNOSTIC_WARN_MSVC(_string)
#
#		undef XTE_DIAGNOSTIC_ERROR
#		define XTE_DIAGNOSTIC_ERROR(_string) XTE_DIAGNOSTIC_ERROR_MSVC(_string)
#
#		undef XTE_DIAGNOSTIC_PUSH
#		define XTE_DIAGNOSTIC_PUSH(_operation, ...) XTE_DIAGNOSTIC_PUSH_MSVC(_operation, __VA_ARGS__)
#
#		undef XTE_DIAGNOSTIC_POP
#		define XTE_DIAGNOSTIC_POP() XTE_DIAGNOSTIC_POP_MSVC()
#	elif XTE_COMPILER_CLANG
#		undef XTE_DIAGNOSTIC_INFO
#		define XTE_DIAGNOSTIC_INFO(_string) XTE_DIAGNOSTIC_INFO_CLANG(_string)
#
#		undef XTE_DIAGNOSTIC_WARN
#		define XTE_DIAGNOSTIC_WARN(_string) XTE_DIAGNOSTIC_WARN_CLANG(_string)
#
#		undef XTE_DIAGNOSTIC_ERROR
#		define XTE_DIAGNOSTIC_ERROR(_string) XTE_DIAGNOSTIC_ERROR_CLANG(_string)
#
#		undef XTE_DIAGNOSTIC_PUSH
#		define XTE_DIAGNOSTIC_PUSH(_operation, ...) XTE_DIAGNOSTIC_PUSH_CLANG(_operation, __VA_ARGS__)
#
#		undef XTE_DIAGNOSTIC_POP
#		define XTE_DIAGNOSTIC_POP() XTE_DIAGNOSTIC_POP_CLANG()
#	elif XTE_COMPILER_GCC
#		undef XTE_DIAGNOSTIC_INFO
#		define XTE_DIAGNOSTIC_INFO(_string) XTE_DIAGNOSTIC_INFO_GCC(_string)
#
#		undef XTE_DIAGNOSTIC_WARN
#		define XTE_DIAGNOSTIC_WARN(_string) XTE_DIAGNOSTIC_WARN_GCC(_string)
#
#		undef XTE_DIAGNOSTIC_ERROR
#		define XTE_DIAGNOSTIC_ERROR(_string) XTE_DIAGNOSTIC_ERROR_GCC(_string)
#
#		undef XTE_DIAGNOSTIC_PUSH
#		define XTE_DIAGNOSTIC_PUSH(_operation, ...) XTE_DIAGNOSTIC_PUSH_GCC(_operation, __VA_ARGS__)
#
#		undef XTE_DIAGNOSTIC_POP
#		define XTE_DIAGNOSTIC_POP() XTE_DIAGNOSTIC_POP_GCC()
#	endif
#
#	if XTE_COMPILER_GCC
#		undef XTE_DIAGNOSTIC_INFO_GCC
#		define XTE_DIAGNOSTIC_INFO_GCC(_string) XTE_PRAGMA(message _string)
#
#		undef XTE_DIAGNOSTIC_WARN_GCC
#		define XTE_DIAGNOSTIC_WARN_GCC(_string) XTE_PRAGMA(GCC warning _string)
#
#		undef XTE_DIAGNOSTIC_ERROR_GCC
#		define XTE_DIAGNOSTIC_ERROR_GCC(_string) XTE_PRAGMA(GCC error _string)
#
#		undef XTE_DIAGNOSTIC_PUSH_GCC
#		define XTE_DIAGNOSTIC_PUSH_GCC(_operation, ...) XTE_PRAGMA(GCC diagnostic push) \
			XTE_IF(XTE_ANY(_operation))(XTE_DIAGNOSTIC_##_operation##_GCC(__VA_ARGS__))()
#
#		undef XTE_DIAGNOSTIC_POP_GCC
#		define XTE_DIAGNOSTIC_POP_GCC() XTE_PRAGMA(GCC diagnostic pop)
#
#		undef XTE_DIAGNOSTIC_ON_GCC
#		define XTE_DIAGNOSTIC_ON_GCC(_id) XTE_PRAGMA(GCC diagnostic warning _id)
#
#		undef XTE_DIAGNOSTIC_STRICT_GCC
#		define XTE_DIAGNOSTIC_STRICT_GCC(_id) XTE_PRAGMA(GCC diagnostic error _id)
#
#		undef XTE_DIAGNOSTIC_OFF_GCC
#		define XTE_DIAGNOSTIC_OFF_GCC(_id) XTE_PRAGMA(GCC diagnostic ignored _id)
#
#		define DETAIL_XTE_DIAGNOSTIC_ON_GCC(_id) 
#	endif
#
#	if XTE_COMPILER_CLANG
#		undef XTE_DIAGNOSTIC_INFO_CLANG
#		define XTE_DIAGNOSTIC_INFO_CLANG(_string) XTE_PRAGMA(message _string)
#
#		undef XTE_DIAGNOSTIC_WARN_CLANG
#		define XTE_DIAGNOSTIC_WARN_CLANG(_string) XTE_PRAGMA(GCC warning _string)
#
#		undef XTE_DIAGNOSTIC_ERROR_CLANG
#		define XTE_DIAGNOSTIC_ERROR_CLANG(_string) XTE_PRAGMA(GCC error _string)
#
#		undef XTE_DIAGNOSTIC_PUSH_CLANG
#		define XTE_DIAGNOSTIC_PUSH_CLANG(_operation, ...) XTE_PRAGMA(clang diagnostic push) \
			XTE_IF(XTE_ANY(_operation))(XTE_DIAGNOSTIC_##_operation##_CLANG(__VA_ARGS__))()
#
#		undef XTE_DIAGNOSTIC_POP_CLANG
#		define XTE_DIAGNOSTIC_POP_CLANG() XTE_PRAGMA(clang diagnostic pop)
#
#		undef XTE_DIAGNOSTIC_ON_CLANG
#		define XTE_DIAGNOSTIC_ON_CLANG(_id) XTE_PRAGMA(clang diagnostic warning _id)
#
#		undef XTE_DIAGNOSTIC_STRICT_CLANG
#		define XTE_DIAGNOSTIC_STRICT_CLANG(_id) XTE_PRAGMA(clang diagnostic error _id)
#
#		undef XTE_DIAGNOSTIC_OFF_CLANG
#		define XTE_DIAGNOSTIC_OFF_CLANG(_id) XTE_PRAGMA(clang diagnostic ignored _id)
#	endif
#
#	if XTE_COMPILER_MSVC
#		undef XTE_DIAGNOSTIC_INFO_MSVC
#		define XTE_DIAGNOSTIC_INFO_MSVC(_string) XTE_PRAGMA(message(_string))
#
#		undef XTE_DIAGNOSTIC_WARN_MSVC
#		define XTE_DIAGNOSTIC_WARN_MSVC(_string) XTE_PRAGMA(message("\x1B[31m" _string "\x1B[0m"))
#
#		undef XTE_DIAGNOSTIC_ERROR_MSVC
#		define XTE_DIAGNOSTIC_ERROR_MSVC(_string) XTE_PRAGMA(message("\x1B[35m" _string "\x1B[0m"))
#
#		undef XTE_DIAGNOSTIC_PUSH_MSVC
#		define XTE_DIAGNOSTIC_PUSH_MSVC(_operation, ...) XTE_PRAGMA(warning(push)) \
			XTE_IF(XTE_ANY(_operation))(XTE_DIAGNOSTIC_##_operation##_MSVC(__VA_ARGS__))()
#
#		undef XTE_DIAGNOSTIC_POP_MSVC
#		define XTE_DIAGNOSTIC_POP_MSVC() XTE_PRAGMA(warning(pop))
#
#		undef XTE_DIAGNOSTIC_ON_MSVC
#		define XTE_DIAGNOSTIC_ON_MSVC(_id) XTE_PRAGMA(warning(default: _id))
#
#		undef XTE_DIAGNOSTIC_STRICT_MSVC
#		define XTE_DIAGNOSTIC_STRICT_MSVC(_id) XTE_PRAGMA(warning(error: _id))
#
#		undef XTE_DIAGNOSTIC_OFF_MSVC
#		define XTE_DIAGNOSTIC_OFF_MSVC(_id) XTE_PRAGMA(warning(disable: _id))
#	endif
#endif

// https://learn.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warnings-c4000-c5999

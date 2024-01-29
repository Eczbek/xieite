#ifndef XIEITE_HEADER_MACROS_ATTRIBUTE
#	define XIEITE_HEADER_MACROS_ATTRIBUTE

#	include "../macros/compiler_type.hpp"
#	include "../macros/compiler_version.hpp"
#	include "../macros/has_attribute.hpp"
#	include "../macros/language_standard.hpp"
#	include "../macros/unused.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2023
#		define XIEITE_ATTRIBUTE_ASSUME(...) [[assume(__VA_ARGS__)]]
#	elif XIEITE_COMPILER_TYPE_GCC && XIEITE_COMPILER_VERSION_LEAST(12, 1)
#		define XIEITE_ATTRIBUTE_ASSUME(...) __attribute__((__assume__(__VA_ARGS__)))
#	elif XIEITE_COMPILER_TYPE_CLANG && XIEITE_COMPILER_VERSION_LEAST(4)
#		define XIEITE_ATTRIBUTE_ASSUME(...) __builtin_assume(__VA_ARGS__)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTRIBUTE_ASSUME(...) __assume(__VA_ARGS__)
#	else
#		define XIEITE_ATTRIBUTE_ASSUME(...) XIEITE_UNUSED()
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2017
#		define XIEITE_ATTRIBUTE_FALLTHROUGH() [[fallthrough]]
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTRIBUTE_FALLTHROUGH() __attribute__((__fallthrough__))
#	elif XIEITE_XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTRIBUTE_FALLTHROUGH() __fallthrough
#	else
#		define XIEITE_ATTRIBUTE_FALLTHROUGH() XIEITE_UNUSED()
#	endif

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTRIBUTE_PACKED(...) __attribute__((__packed__)) __VA_ARGS__
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTRIBUTE_PACKED(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#	else
#		define XIEITE_ATTRIBUTE_PACKED(...) __VA_ARGS__
#	endif

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTRIBUTE_FORCE_INLINE __attribute__((__always_inline__)) inline
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTRIBUTE_FORCE_INLINE __forceinline
#	else
#		define XIEITE_ATTRIBUTE_FORCE_INLINE inline
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
#		define XIEITE_ATTRIBUTE_LIKELY [[likely]]
#	else
#		define XIEITE_ATTRIBUTE_LIKELY
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
#		define XIEITE_ATTRIBUTE_UNLIKELY [[unlikely]]
#	else
#		define XIEITE_ATTRIBUTE_UNLIKELY
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2017
#		define XIEITE_ATTRIBUTE_MAYBE_UNUSED [[maybe_unused]]
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTRIBUTE_MAYBE_UNUSED __attribute__((__unused__))
#	else
#		define XIEITE_ATTRIBUTE_MAYBE_UNUSED
#	endif

#	if (XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG) && XIEITE_HAS_ATTRIBUTE(__nodebug__)
#		define XIEITE_ATTRIBUTE_NO_DEBUG __attribute__((__nodebug__))
#	else
#		define XIEITE_ATTRIBUTE_NO_DEBUG
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2017
#		define XIEITE_ATTRIBUTE_NO_DISCARD [[nodiscard]]
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIETIE_NO_DISCARD __attribute__((__warn_unused_result__))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTRIBUTE_NO_DISCARD __checkReturn
#	else
#		define XIEITE_ATTRIBUTE_NO_DISCARD
#	endif

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTRIBUTE_NO_INLINE __attribute__((__noinline__))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTRIBUTE_NO_INLINE __declspec(noinline)
#	else
#		define XIEITE_ATTRIBUTE_NO_INLINE
#	endif

#	if XIEITE_LANGUAGE_STANDARD_CPP_2011 || XIEITE_LANGUAGE_STANDARD_C_2023
#		define XIEITE_ATTRIBUTE_NO_RETURN [[noreturn]]
#	elif XIEITE_LANGUAGE_STANDARD_C_2011
#		define XIEITE_ATTRIBUTE_NO_RETURN _Noreturn
#	elif XIEITE_COMPILER_TYPE_GCC && XIEITE_COMPILER_VERSION_LEAST(2, 5)
#		define XIEITE_ATTRIBUTE_NO_RETURN __attribute__((__noreturn__))
#	else
#		define XIEITE_ATTRIBUTE_NO_RETURN
#	endif

#	if XIEITE_COMPILER_TYPE_GCC
#		define XIEITE_ATTRIBUTE_STANDARD_CALL __attribute__((__stdcall__))
#	elif XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTRIBUTE_STANDARD_CALL __stdcall
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTRIBUTE_STANDARD_CALL __cdecl
#	else
#		define XIEITE_ATTRIBUTE_STANDARD_CALL
#	endif

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTRIBUTE_USED __attribute__((__used__))
#	else
#		define XIEITE_ATTRIBUTE_USED
#	endif

#endif

// Thanks to eightfold (https://github.com/8ightfold) and Ian Pike (https://github.com/Rinzii) for some original code

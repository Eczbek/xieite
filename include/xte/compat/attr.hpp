#ifndef DETAIL_XTE_HEADER_PREPROC_ATTR
#	define DETAIL_XTE_HEADER_PREPROC_ATTR
#
#	include "../detect/compiler.hpp"
#	include "../detect/feature.hpp"
#	include "../detect/lang.hpp"
#
#	if XTE_LANG(CPP, >=, 2011)
#		define XTE_ATTR_ALIGN(...) alignas(__VA_ARGS__)
#	elif XTE_LANG(C, >=, 2011)
#		define XTE_ATTR_ALIGN(...) _Alignas(__VA_ARGS__)
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_ALIGN(...) __declspec(align(__VA_ARGS__))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_ATTR_ALIGN(...) __attribute__((__aligned__(__VA_ARGS__)))
#	else
#		define XTE_ATTR_ALIGN(...)
#	endif
#
#	if XTE_LANG(CPP, >=, 2023)
#		define XTE_ATTR_ASSUME(...) [[assume(__VA_ARGS__)]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_ASSUME(...) __assume(__VA_ARGS__)
#	elif XTE_COMPILER(CLANG, >=, 4)
#		define XTE_ATTR_ASSUME(...) __builtin_assume(__VA_ARGS__)
#	elif XTE_COMPILER(GCC, >=, 7,1) || XTE_COMPILER_CLANG
#		define XTE_ATTR_ASSUME(...) __attribute__((__assume__(__VA_ARGS__)))
#	else
#		define XTE_ATTR_ASSUME(...) do; while (0)
#	endif
#
#	if XTE_COMPILER(GCC, >=, 4,4) || XTE_COMPILER(CLANG, >=, 3,2)
#		if (XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023))
#			define XTE_ATTR_COLD [[gnu::cold]]
#		else
#			define XTE_ATTR_COLD __attribute__((cold))
#		endif
#	else
#		define XTE_ATTR_COLD
#	endif
#
#	if XTE_LANG(CPP, >=, 2014) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_DEPRECATED [[deprecated]]
#		define XTE_ATTR_DEPRECATED_MESSAGE(MESSAGE) [[deprecated(MESSAGE)]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_DEPRECATED __declspec(deprecated)
#		define XTE_ATTR_DEPRECATED_MESSAGE(MESSAGE) __declspec(deprecated(MESSAGE))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011)
#			define XTE_ATTR_DEPRECATED [[gnu::deprecated]]
#			define XTE_ATTR_DEPRECATED_MESSAGE(MESSAGE) [[gnu::deprecated(__VA_ARGS__)]]
#		else
#			define XTE_ATTR_DEPRECATED __attribute__((__deprecated__))
#			define XTE_ATTR_DEPRECATED_MESSAGE(MESSAGE) __attribute__((__deprecated__(MESSAGE)))
#		endif
#	else
#		define XTE_ATTR_DEPRECATED
#		define XTE_ATTR_DEPRECATED_MESSAGE(MESSAGE)
#	endif
#
#	if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_EXITS [[noreturn]]
#	elif XTE_LANG(C, >=, 2011)
#		define XTE_ATTR_EXITS _Noreturn
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_EXITS __declspec(noreturn)
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_ATTR_EXITS __attribute__((__noreturn__))
#	else
#		define XTE_ATTR_EXITS
#	endif
#
#	if XTE_LANG(CPP, >=, 2017) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_FALLTHROUGH() [[fallthrough]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_FALLTHROUGH() __fallthrough
#	elif XTE_COMPILER(GCC, >=, 7) || XTE_COMPILER(CLANG, >=, 10)
#		define XTE_ATTR_FALLTHROUGH() __attribute__((__fallthrough__))
#	else
#		define XTE_ATTR_FALLTHROUGH() do; while (0)
#	endif
#
#	if XTE_COMPILER_MSVC
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_FORCE_INLINE [[msvc::forceinline]] inline
#		else
#			define XTE_ATTR_FORCE_INLINE __forceinline
#		endif
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_FORCE_INLINE [[gnu::always_inline]] inline
#		else
#			define XTE_ATTR_FORCE_INLINE __attribute__((__always_inline__)) inline
#		endif
#	else
#		define XTE_ATTR_FORCE_INLINE inline
#	endif
#
#	if XTE_COMPILER(GCC, >=, 4,4) || XTE_COMPILER(CLANG, >=, 3,2)
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_HOT [[gnu::hot]]
#		else
#			define XTE_ATTR_HOT __attribute__((__hot__))
#		endif
#	else
#		define XTE_ATTR_HOT
#	endif
#
#	if (XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)) && XTE_COMPILER(CLANG, >=, 8)
#		define XTE_ATTR_UNINITIALIZED [[clang::uninitialized]]
#	elif (XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)) && XTE_COMPILER(GCC, >=, 16)
#		define XTE_ATTR_UNINITIALIZED [[uninitialized]]
#	elif XTE_COMPILER(CLANG, >=, 8) || XTE_COMPILER(GCC, >=, 12)
#		define XTE_ATTR_UNINITIALIZED __attribute__((__uninitialized__))
#	elif XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_UNINITIALIZED [[]]
#	else
#		define XTE_ATTR_UNINITIALIZED
#	endif
#
#	if XTE_LANG(CPP, >=, 2020)
#		define XTE_ATTR_LIKELY [[likely]]
#	else
#		define XTE_ATTR_LIKELY
#	endif
#
#	if XTE_COMPILER(MSVC, >=, 16,9)
#		define XTE_ATTR_NO_UNIQUE_ADDR [[msvc::no_unique_address]]
#	elif XTE_LANG(CPP, >=, 2020)
#		define XTE_ATTR_NO_UNIQUE_ADDR [[no_unique_address]]
#	else
#		define XTE_ATTR_NO_UNIQUE_ADDR
#	endif
#
#	if XTE_LANG(CPP, >=, 2017)
#		define XTE_ATTR_NOEX noexcept(true)
#	elif XTE_LANG_CPP
#		define XTE_ATTR_NOEX throw()
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_NOEX __declspec(nothrow)
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_NOEX [[gnu::nothrow]]
#		else
#			define XTE_ATTR_NOEX __attribute__((__nothrow__))
#		endif
#	else
#		define XTE_ATTR_NOEX
#	endif
#
#	if XTE_COMPILER(GCC, >=, 4,4) && !XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_OPTIMIZE(NAME) [[gnu::optimize(NAME)]]
#		else
#			define XTE_ATTR_OPTIMIZE(NAME) __attribute__((__optimize__(NAME)))
#		endif
#	else
#		define XTE_ATTR_OPTIMIZE(...)
#	endif
#
#	if XTE_COMPILER_MSVC
#		define XTE_ATTR_PACK(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_PACK(...) [[gnu::packed]] __VA_ARGS__
#		else
#			define XTE_ATTR_PACK(...) __attribute__((__packed__)) __VA_ARGS__
#		endif
#	else
#		define XTE_ATTR_PACK(...) __VA_ARGS__
#	endif
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_PURE [[gnu::pure]]
#		else
#			define XTE_ATTR_PURE __attribute__((__pure__))
#		endif
#	else
#		define XTE_ATTR_PURE
#	endif
#
#	if XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_REPRODUCIBLE [[reproducible]]
#	elif XTE_COMPILER(GCC, >=, 15) && !XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011)
#			define XTE_ATTR_REPRODUCIBLE [[gnu::reproducible]]
#		else
#			define XTE_ATTR_REPRODUCIBLE __attribute__((__reproducible__))
#		endif
#	else
#		define XTE_ATTR_REPRODUCIBLE
#	endif
#
#	if XTE_COMPILER_MSVC
#		define XTE_ATTR_SECTION(NAME) __declspec(allocate(NAME))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_SECTION(NAME) [[gnu::section(NAME)]]
#		else
#			define XTE_ATTR_SECTION(NAME) __attribute__((__section__(NAME)))
#		endif
#	else
#		define XTE_ATTR_SECTION(NAME)
#	endif
#
#	if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#		if XTE_COMPILER_CLANG
#			define XTE_ATTR_UNAVAIL [[clang::unavailable]]
#		elif XTE_COMPILER(GCC, >=, 12)
#			define XTE_ATTR_UNAVAIL [[gnu::unavailable]]
#		else
#			define XTE_ATTR_UNAVAIL [[]]
#		endif
#	elif XTE_COMPILER(GCC, >=, 12) || XTE_COMPILER_CLANG
#		define XTE_ATTR_UNAVAIL __attribute__((__unavailable__))
#	else
#		define XTE_ATTR_UNAVAIL
#	endif
#
#	if XTE_COMPILER_MSVC
#		define XTE_ATTR_UNINLINE __declspec(noinline)
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_UNINLINE [[gnu::noinline]]
#		else
#			define XTE_ATTR_UNINLINE __attribute__((__noinline__))
#		endif
#	else
#		define XTE_ATTR_UNINLINE
#	endif
#
#	if XTE_LANG(CPP, >=, 2020)
#		define XTE_ATTR_UNLIKELY [[unlikely]]
#	else
#		define XTE_ATTR_UNLIKELY
#	endif
#
#	if XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_UNSEQ [[unsequenced]]
#	elif XTE_COMPILER(GCC, >=, 15) && !XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011)
#			define XTE_ATTR_UNSEQ [[gnu::unsequenced]]
#		else
#			define XTE_ATTR_UNSEQ __attribute__((__unsequenced__))
#		endif
#	else
#		define XTE_ATTR_UNSEQ
#	endif
#
#	if XTE_LANG(CPP, >=, 2017)
#		define XTE_ATTR_UNUSED [[maybe_unused]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_UNUSED __pragma(warning(suppress: 4100 4101 4189 4505))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_UNUSED [[gnu::unused]]
#		else
#			define XTE_ATTR_UNUSED __attribute__((__unused__))
#		endif
#	else
#		define XTE_ATTR_UNUSED
#	endif
#
#	if XTE_LANG(CPP, >=, 2017) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_USED_RESULT [[nodiscard]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_USED_RESULT __checkReturn
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011)
#			define XTE_ATTR_USED_RESULT [[gnu::warn_unused_result]]
#		else
#			define XTE_ATTR_USED_RESULT __attribute__((__warn_unused_result__))
#		endif
#	else
#		define XTE_ATTR_USED_RESULT
#	endif
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_VISIBLE(NAME)  [[gnu::visibility(#NAME)]]
#		else
#			define XTE_ATTR_VISIBLE(NAME) __attribute__((__visibility__(#NAME)))
#		endif
#	else
#		define XTE_ATTR_VISIBLE(NAME)
#	endif
#endif

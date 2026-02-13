#ifndef DETAIL_XTE_HEADER_PREPROC_ATTR
#	define DETAIL_XTE_HEADER_PREPROC_ATTR
#
#	include "../preproc/compiler.hpp"
#	include "../preproc/has_attr.hpp"
#	include "../preproc/lang.hpp"
#
#	if XTE_LANG(CPP, >=, 2011)
#		define XTE_ATTR_ALIGN(...) alignas(__VA_ARGS__)
#	elif XTE_LANG(C, >=, 2011)
#		define XTE_ATTR_ALIGN(...) _Alignas(__VA_ARGS__)
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_ALIGN(...) __declspec(align(__VA_ARGS__))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_ATTR_ALIGN(...) __attribute__((aligned(__VA_ARGS__)))
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
#		define XTE_ATTR_ASSUME(...) __attribute__((assume(__VA_ARGS__)))
#	else
#		define XTE_ATTR_ASSUME(...) do; while (0)
#	endif
#
#	if XTE_COMPILER(GCC, >=, 4,4) || XTE_COMPILER(CLANG, >=, 3,2)
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_COLD [[gnu::cold]]
#		else
#			define XTE_ATTR_COLD __attribute__((cold))
#		endif
#	else
#		define XTE_ATTR_COLD
#	endif
#
#	if XTE_LANG(CPP, >=, 2014) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_DEPRECATED(...) [[deprecated __VA_OPT__((__VA_ARGS__))]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_DEPRECATED(...) __declspec(deprecated __VA_OPT__((__VA_ARGS__)))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011)
#			define XTE_ATTR_DEPRECATED(...) [[gnu::deprecated __VA_OPT__((__VA_ARGS__))]]
#		else
#			define XTE_ATTR_DEPRECATED(...) __attribute__((deprecated(__VA_ARGS__)))
#		endif
#	else
#		define XTE_ATTR_DEPRECATED(...)
#	endif
#
#	if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_EXITS [[noreturn]]
#	elif XTE_LANG(C, >=, 2011)
#		define XTE_ATTR_EXITS _Noreturn
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_EXITS __declspec(noreturn)
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_ATTR_EXITS __attribute__((noreturn))
#	else
#		define XTE_ATTR_EXITS
#	endif
#
#	if XTE_LANG(CPP, >=, 2017) || XTE_LANG(C, >=, 2023)
#		define XTE_ATTR_FALLTHROUGH() [[fallthrough]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_FALLTHROUGH() __fallthrough
#	elif XTE_COMPILER(GCC, >=, 7) || XTE_COMPILER(CLANG, >=, 10)
#		define XTE_ATTR_FALLTHROUGH() __attribute__((fallthrough))
#	else
#		define XTE_ATTR_FALLTHROUGH() do; while (0)
#	endif
#
#	if XTE_COMPILER_MSVC
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_INLINE [[msvc::forceinline]] inline
#		else
#			define XTE_ATTR_INLINE __forceinline
#		endif
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_INLINE [[gnu::always_inline]] inline
#		else
#			define XTE_ATTR_INLINE __attribute__((always_inline)) inline
#		endif
#	else
#		define XTE_ATTR_INLINE inline
#	endif
#
#	if XTE_COMPILER(GCC, >=, 4,4) || XTE_COMPILER(CLANG, >=, 3,2)
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_HOT [[gnu::hot]]
#		else
#			define XTE_ATTR_HOT __attribute__((hot))
#		endif
#	else
#		define XTE_ATTR_HOT
#	endif
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_VISIBLE(_type)  [[gnu::visibility(#_type)]]
#		else
#			define XTE_ATTR_VISIBLE(_type) __attribute__((visibility(#_type)))
#		endif
#	else
#		define XTE_ATTR_VISIBLE(_type)
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
#			define XTE_ATTR_NOEX __attribute__((nothrow))
#		endif
#	else
#		define XTE_ATTR_NOEX
#	endif
#
#	if XTE_COMPILER(GCC, >=, 4,4) && !XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_OPTIMIZE(_opt) [[gnu::optimize(_opt)]]
#		else
#			define XTE_ATTR_OPTIMIZE(_opt) __attribute__((optimize(_opt)))
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
#			define XTE_ATTR_PACK(...) __attribute__((packed)) __VA_ARGS__
#		endif
#	else
#		define XTE_ATTR_PACK(...) __VA_ARGS__
#	endif
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_PURE [[gnu::pure]]
#		else
#			define XTE_ATTR_PURE __attribute__((pure))
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
#			define XTE_ATTR_REPRODUCIBLE __attribute__((reproducible))
#		endif
#	else
#		define XTE_ATTR_REPRODUCIBLE
#	endif
#
#	if XTE_COMPILER_MSVC
#		define XTE_ATTR_SECTION(_name) __declspec(allocate(_name))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_SECTION(_name) [[gnu::section(_name)]]
#		else
#			define XTE_ATTR_SECTION(_name) __attribute__((section(_name)))
#		endif
#	else
#		define XTE_ATTR_SECTION(_name)
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
#		define XTE_ATTR_UNAVAIL __attribute__((unavailable))
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
#			define XTE_ATTR_UNINLINE __attribute__((noinline))
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
#			define XTE_ATTR_UNSEQ __attribute__((unsequenced))
#		endif
#	else
#		define XTE_ATTR_UNSEQ
#	endif
#
#	if XTE_LANG(CPP, >=, 2017)
#		define XTE_ATTR_UNUSED [[maybe_unused]]
#	elif XTE_COMPILER_MSVC
#		define XTE_ATTR_UNUSED __pragma(warning(suppress: 4100 4101 4505))
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		if XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 2023)
#			define XTE_ATTR_UNUSED [[gnu::unused]]
#		else
#			define XTE_ATTR_UNUSED __attribute__((unused))
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
#			define XTE_ATTR_USED_RESULT __attribute__((warn_unused_result))
#		endif
#	else
#		define XTE_ATTR_USED_RESULT
#	endif
#endif

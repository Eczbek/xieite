#ifndef DETAIL_XIEITE_HEADER_PP_ATTR
#	define DETAIL_XIEITE_HEADER_PP_ATTR
#
#	include "../pp/compiler.hpp"
#	include "../pp/has_attr.hpp"
#	include "../pp/lang.hpp"
#
#	if XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_ALIGN(...) alignas(__VA_ARGS__)
#	elif XIEITE_LANG_VER(C, >=, 2011)
#		define XIEITE_ATTR_ALIGN(...) _Alignas(__VA_ARGS__)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_ALIGN(...) __declspec(align(__VA_ARGS__))
#	elif XIEITE_HAS_ATTR(__aligned__)
#		define XIEITE_ATTR_ALIGN(...) __attribute__((__aligned__(__VA_ARGS__)))
#	else
#		define XIEITE_ATTR_ALIGN(...)
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2023)
#		define XIEITE_ATTR_ASSUME(...) [[assume(__VA_ARGS__)]]
#	elif XIEITE_COMPILER_VER(GCC, >=, 12, 1)
#		define XIEITE_ATTR_ASSUME(...) __attribute__((__assume__(__VA_ARGS__)))
#	elif XIEITE_COMPILER_VER(CLANG, >=, 4)
#		define XIEITE_ATTR_ASSUME(...) __builtin_assume(__VA_ARGS__)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_ASSUME(...) __assume(__VA_ARGS__)
#	else
#		define XIEITE_ATTR_ASSUME(...) void()
#	endif
#
#	if XIEITE_HAS_ATTR(__cold__)
#		define XIEITE_ATTR_COLD __attribute__((__cold__))
#	else
#		define XIEITE_ATTR_COLD
#	endif
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_DEPREC __declspec(deprecated)
#	elif XIEITE_LANG_VER(CPP, >=, 2014) || XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_DEPREC [[deprecated]]
#	elif XIEITE_HAS_ATTR(__deprecated__)
#		define XIEITE_ATTR_DEPREC __attribute__((__deprecated__))
#	else
#		define XIEITE_ATTR_DEPREC
#	endif
#
#	ifdef XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_EMPTY_BASES __declspec(empty_bases)
#	else
#		define XIEITE_ATTR_EMPTY_BASES
#	endif
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_EXPORT __declspec(dllexport)
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_EXPORT __attribute__((__visibility__("default")))
#	else
#		define XIEITE_ATTR_EXPORT
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017) || (XIEITE_COMPILER_VER(GCC, >=, 8) && XIEITE_LANG_VER(CPP, >=, 2011))
#		define XIEITE_ATTR_FALLTHR() [[fallthrough]]
#	elif XIEITE_COMPILER_VER(GCC, >=, 7) || XIEITE_COMPILER_VER(LLC, >=, 125, 5) || (XIEITE_COMPILER_VER(LLC, <, 125) && XIEITE_COMPILER_VER(LLC, >=, 124, 12))
#		define XIEITE_ATTR_FALLTHR() __attribute__((__fallthrough__))
#	elif XIEITE_COMPILER_TYPE_CLANG && XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_FALLTHR() [[clang::fallthrough]]
#	elif XIEITE_XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FALLTHR() __fallthrough
#	else
#		define XIEITE_ATTR_FALLTHR() void()
#	endif
#
#	if XIEITE_HAS_ATTR(__flatten__)
#		define XIEITE_ATTR_FLAT __attribute__((__flatten__))
#	else
#		define XIEITE_ATTR_FLAT
#	endif
#
#	if XIEITE_HAS_ATTR(__always_inline__)
#		define XIEITE_ATTR_FORCEINL __attribute__((__always_inline__)) inline
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FORCEINL __forceinline
#	else
#		define XIEITE_ATTR_FORCEINL inline
#	endif
#
#	if XIEITE_HAS_ATTR(__hot__)
#		define XIEITE_ATTR_HOT __attribute__((__hot__))
#	else
#		define XIEITE_ATTR_HOT
#	endif
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_IMPORT __declspec(dllimport)
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_IMPORT __attribute__((__visibility__("default")))
#	else
#		define XIEITE_ATTR_IMPORT
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_LIKELY [[likely]]
#	else
#		define XIEITE_ATTR_LIKELY
#	endif
#
#	if (XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG) && !XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_LOCAL __attribute__((__visibility__("hidden")))
#	else
#		define XIEITE_ATTR_LOCAL
#	endif
#
#	if XIEITE_HAS_ATTR(__nodebug__)
#		define XIEITE_ATTR_NODEBUG __attribute__((__nodebug__))
#	else
#		define XIEITE_ATTR_NODEBUG
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_NODISCARD [[nodiscard]]
#	elif XIEITE_HAS_ATTR(__warn_unused_result__)
#		define XIEITE_ATTR_NODISCARD __attribute__((__warn_unused_result__))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NODISCARD __checkReturn
#	else
#		define XIEITE_ATTR_NODISCARD
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_NOEX noexcept(true)
#	elif XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_NOEX throw()
#	elif XIEITE_HAS_ATTR(__nothrow__)
#		define XIEITE_ATTR_NOEX __attribute__((__nothrow__))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NOEX __declspec(nothrow)
#	else
#		define XIEITE_ATTR_NOEX
#	endif
#
#	if XIEITE_HAS_ATTR(__noinline__)
#		define XIEITE_ATTR_NOINL __attribute__((__noinline__))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NOINL __declspec(noinline)
#	else
#		define XIEITE_ATTR_NOINL
#	endif
#
#	if XIEITE_HAS_ATTR(__nonnull__)
#		define XIEITE_ATTR_NONNULL __attribute__((__nonnull__))
#	else
#		define XIEITE_ATTR_NONNULL
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2011) || XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_NORET [[noreturn]]
#	elif XIEITE_LANG_VER(C, >=, 2011)
#		define XIEITE_ATTR_NORET _Noreturn
#	elif XIEITE_HAS_ATTR(__noreturn__)
#		define XIEITE_ATTR_NORET __attribute__((__noreturn__))
#	else
#		define XIEITE_ATTR_NORET
#	endif
#
#	if XIEITE_COMPILER_VER(MSVC, >=, 16, 9)
#		define XIEITE_ATTR_NOUNIQADDR [[msvc::no_unique_address]]
#	elif XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_NOUNIQADDR [[no_unique_address]]
#	else
#		define XIEITE_ATTR_NOUNIQADDR
#	endif
#
#	if XIEITE_COMPILER_TYPE_GCC
#		define XIEITE_ATTR_OPTIMIZE(...) __attribute__((__optimize__(__VA_ARGS__)))
#	else
#		define XIEITE_ATTR_OPTIMIZE(...)
#	endif
#
#	if XIEITE_HAS_ATTR(__packed__)
#		define XIEITE_ATTR_PACK(...) __attribute__((__packed__)) __VA_ARGS__
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_PACK(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#	else
#		define XIEITE_ATTR_PACK(...) __VA_ARGS__
#	endif
#
#	if XIEITE_HAS_ATTR(__returns_nonnull__)
#		define XIEITE_ATTR_RETNONNULL __attribute__((__returns_nonnull__))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_RETNONNULL _Ret_notnull_
#	else
#		define XIEITE_ATTR_RETNONNULL
#	endif
#
#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_SECTION(...) __attribute__((__section__(__VA_ARGS__)))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_SECTION(...) __declspec(allocate(__VA_ARGS__))
#	else
#		define XIEITE_ATTR_SECTION(...)
#	endif
#
#	if XIEITE_HAS_ATTR(__stdcall__)
#		define XIEITE_ATTR_STDCALL __attribute__((__stdcall__))
#	elif XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_STDCALL __stdcall
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_STDCALL __cdecl
#	else
#		define XIEITE_ATTR_STDCALL
#	endif
#
#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_TAIL __attribute__((__musttail__))
#	else
#		define XIEITE_ATTR_TAIL
#	endif
#
#	if XIEITE_COMPILER_TYPE_MSVC || XIEITE_COMPILER_TYPE_DATALIGHT_C
#		define XIEITE_ATTR_THREAD __declspec(thread)
#	else
#		define XIEITE_ATTR_THREAD
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_UNLIKELY [[unlikely]]
#	else
#		define XIEITE_ATTR_UNLIKELY
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_UNUSED [[maybe_unused]]
#	elif XIEITE_HAS_ATTR(__unused__)
#		define XIEITE_ATTR_UNUSED __attribute__((__unused__))
#	else
#		define XIEITE_ATTR_UNUSED
#	endif
#
#	if XIEITE_HAS_ATTR(__used__)
#		define XIEITE_ATTR_USED __attribute__((__used__))
#	else
#		define XIEITE_ATTR_USED
#	endif
#
#	if XIEITE_HAS_ATTR(__weak__)
#		define XIEITE_ATTR_WEAK __attribute__((__weak__))
#	else
#		define XIEITE_ATTR_WEAK
#	endif
#endif

// https://github.com/isar/libmdbx/blob/master/src/preface.h
// Thanks to eightfold (https://github.com/8ightfold) and Ian Pike (https://github.com/Rinzii) for some original code

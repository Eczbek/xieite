#pragma once

#include <xieite/cplr.hpp>
#include <xieite/has_attr.hpp>
#include <xieite/lang.hpp>

#if XIEITE_LANG_LEAST(CPP, 2011)
#	define XIEITE_ATTR_ALIGN_AS(...) alignas(__VA_ARGS__)
#elif XIEITE_LANG_LEAST(C, 2011)
#	define XIEITE_ATTR_ALIGN_AS(...) _Alignas(__VA_ARGS__)
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_ALIGN_AS(...) __declspec(align(__VA_ARGS__))
#elif XIEITE_HAS_ATTR(__aligned__)
#	define XIEITE_ATTR_ALIGN_AS(...) __attribute__((__aligned__(__VA_ARGS__)))
#else
#	define XIEITE_ATTR_ALIGN_AS(...)
#endif

#if XIEITE_LANG_LEAST(CPP, 2023)
#	define XIEITE_ATTR_ASSUME(...) [[assume(__VA_ARGS__)]]
#elif XIEITE_CPLR_LEAST(GCC, 12, 1)
#	define XIEITE_ATTR_ASSUME(...) __attribute__((__assume__(__VA_ARGS__)))
#elif XIEITE_CPLR_LEAST(CLANG, 4)
#	define XIEITE_ATTR_ASSUME(...) __builtin_assume(__VA_ARGS__)
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_ASSUME(...) __assume(__VA_ARGS__)
#else
#	define XIEITE_ATTR_ASSUME(...) void()
#endif

#if XIEITE_HAS_ATTR(__cold__)
#	define XIEITE_ATTR_COLD __attribute__((__cold__))
#else
#	define XIEITE_ATTR_COLD
#endif

#if XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_DEPRECATED __declspec(deprecated)
#elif XIEITE_LANG_LEAST(CPP, 2014) || XIEITE_LANG_LEAST(C, 2023)
#	define XIEITE_ATTR_DEPRECATED [[deprecated]]
#elif XIEITE_HAS_ATTR(__deprecated__)
#	define XIEITE_ATTR_DEPRECATED __attribute__((__deprecated__))
#else
#	define XIEITE_ATTR_DEPRECATED
#endif

#if XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_EXPORT __declspec(dllexport)
#elif XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#	define XIEITE_ATTR_EXPORT __attribute__((__visibility__("default")))
#else
#	define XIEITE_ATTR_EXPORT
#endif

#if XIEITE_LANG_LEAST(CPP, 2017) || (XIEITE_CPLR_LEAST(GCC, 8) && XIEITE_LANG_LEAST(CPP, 2011))
#	define XIEITE_ATTR_FALLTHROUGH() [[fallthrough]]
#elif XIEITE_CPLR_LEAST(GCC, 7) && (!XIEITE_CPLR_TYPE_LCC || ((XIEITE_CPLR_MAJOR_LCC == 124) && (XIEITE_CPLR_MINOR_LCC >= 12)) || ((XIEITE_CPLR_MAJOR_LCC == 125) && (XIEITE_CPLR_MINOR_LCC >= 5)) || (XIEITE_CPLR_MAJOR_LCC >= 126))
#	define XIEITE_ATTR_FALLTHROUGH() __attribute__((__fallthrough__))
#elif XIEITE_CPLR_TYPE_CLANG && XIEITE_LANG_LEAST(CPP, 2011)
#	define XIEITE_ATTR_FALLTHROUGH() [[clang::fallthrough]]
#elif XIEITE_XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_FALLTHROUGH() __fallthrough
#else
#	define XIEITE_ATTR_FALLTHROUGH() void()
#endif

#if XIEITE_HAS_ATTR(__flatten__)
#	define XIEITE_ATTR_FLATTEN __attribute__((__flatten__))
#else
#	define XIEITE_ATTR_FLATTEN
#endif

#if XIEITE_HAS_ATTR(__always_inline__)
#	define XIEITE_ATTR_FORCE_INLINE __attribute__((__always_inline__)) inline
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_FORCE_INLINE __forceinline
#else
#	define XIEITE_ATTR_FORCE_INLINE inline
#endif

#if XIEITE_HAS_ATTR(__hot__)
#	define XIEITE_ATTR_HOT __attribute__((__hot__))
#else
#	define XIEITE_ATTR_HOT
#endif

#if XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_IMPORT __declspec(dllimport)
#elif XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#	define XIEITE_ATTR_IMPORT __attribute__((__visibility__("default")))
#else
#	define XIEITE_ATTR_IMPORT
#endif

#if XIEITE_LANG_LEAST(CPP, 2020)
#	define XIEITE_ATTR_LIKELY [[likely]]
#else
#	define XIEITE_ATTR_LIKELY
#endif

#if (XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG) && !XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_LOCAL __attribute__((__visibility__("hidden")))
#else
#	define XIEITE_ATTR_LOCAL
#endif

#if XIEITE_LANG_LEAST(CPP, 2017)
#	define XIEITE_ATTR_MAYBE_UNUSED [[maybe_unused]]
#elif XIEITE_HAS_ATTR(__unused__)
#	define XIEITE_ATTR_MAYBE_UNUSED __attribute__((__unused__))
#else
#	define XIEITE_ATTR_MAYBE_UNUSED
#endif

#if XIEITE_HAS_ATTR(__nodebug__)
#	define XIEITE_ATTR_NO_DEBUG __attribute__((__nodebug__))
#else
#	define XIEITE_ATTR_NO_DEBUG
#endif

#if XIEITE_LANG_LEAST(CPP, 2017)
#	define XIEITE_ATTR_NO_DISCARD [[nodiscard]]
#elif XIEITE_HAS_ATTR(__warn_unused_result__)
#	define XIEITE_NO_DISCARD __attribute__((__warn_unused_result__))
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_NO_DISCARD __checkReturn
#else
#	define XIEITE_ATTR_NO_DISCARD
#endif

#if XIEITE_HAS_ATTR(__noinline__)
#	define XIEITE_ATTR_NO_INLINE __attribute__((__noinline__))
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_NO_INLINE __declspec(noinline)
#else
#	define XIEITE_ATTR_NO_INLINE
#endif

#if XIEITE_LANG_LEAST(CPP, 2011) || XIEITE_LANG_LEAST(C, 2023)
#	define XIEITE_ATTR_NO_RETURN [[noreturn]]
#elif XIEITE_LANG_C >= 2011
#	define XIEITE_ATTR_NO_RETURN _Noreturn
#elif XIEITE_HAS_ATTR(__noreturn__)
#	define XIEITE_ATTR_NO_RETURN __attribute__((__noreturn__))
#else
#	define XIEITE_ATTR_NO_RETURN
#endif

#if XIEITE_LANG_LEAST(CPP, 2017)
#	define XIEITE_ATTR_NO_THROW noexcept(true)
#elif XIEITE_LANG_LEAST(CPP, 2011)
#	define XIEITE_ATTR_NO_THROW throw()
#elif XIEITE_HAS_ATTR(__nothrow__)
#	define XIEITE_ATTR_NO_THROW __attribute__((__nothrow__))
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_NO_THROW __declspec(nothrow)
#else
#	define XIEITE_ATTR_NO_THROW
#endif

#if XIEITE_CPLR_LEAST(MSVC, 16, 9)
#	define XIEITE_ATTR_NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#elif XIEITE_LANG_LEAST(CPP, 2020)
#	define XIEITE_ATTR_NO_UNIQUE_ADDRESS [[no_unique_address]]
#else
#	define XIEITE_ATTR_NO_UNIQUE_ADDRESS
#endif

#if XIEITE_HAS_ATTR(__nonnull__)
#	define XIEITE_ATTR_NON_NULL __attribute__((__nonnull__))
#else
#	define XIEITE_ATTR_NON_NULL
#endif

#if XIEITE_CPLR_TYPE_GCC
#	define XIEITE_ATTR_OPTIMIZE(...) __attribute__((__optimize__(__VA_ARGS__)))
#else
#	define XIEITE_ATTR_OPTIMIZE(...)
#endif

#if XIEITE_HAS_ATTR(__packed__)
#	define XIEITE_ATTR_PACKED(...) __attribute__((__packed__)) __VA_ARGS__
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_PACKED(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#else
#	define XIEITE_ATTR_PACKED(...) __VA_ARGS__
#endif

#if XIEITE_HAS_ATTR(__returns_nonnull__)
#	define XIEITE_ATTR_RETURNS_NON_NULL __attribute__((__returns_nonnull__))
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_RETURNS_NON_NULL _Ret_notnull_
#else
#	define XIEITE_ATTR_RETURNS_NON_NULL
#endif

#if XIEITE_CPLR_TYPE_GCC || XIEITE_CPLR_TYPE_CLANG
#	define XIETIE_ATTRIBUTE_SECTION(...) __attribute__((__section__(__VA_ARGS__)))
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_SECTION(...) __declspec(allocate(__VA_ARGS__))
#else
#	define XIEITE_ATTR_SECTION(...)
#endif

#if XIEITE_HAS_ATTR(__stdcall__)
#	define XIEITE_ATTR_STANDARD_CALL __attribute__((__stdcall__))
#elif XIEITE_CPLR_TYPE_CLANG
#	define XIEITE_ATTR_STANDARD_CALL __stdcall
#elif XIEITE_CPLR_TYPE_MSVC
#	define XIEITE_ATTR_STANDARD_CALL __cdecl
#else
#	define XIEITE_ATTR_STANDARD_CALL
#endif

#if XIEITE_CPLR_TYPE_MSVC || XIEITE_CPLR_TYPE_DATALIGHT_C
#	define XIEITE_ATTR_THREAD __declspec(thread)
#else
#	define XIEITE_ATTR_THREAD
#endif

#if XIEITE_LANG_LEAST(CPP, 2020)
#	define XIEITE_ATTR_UNLIKELY [[unlikely]]
#else
#	define XIEITE_ATTR_UNLIKELY
#endif

#if XIEITE_HAS_ATTR(__used__)
#	define XIEITE_ATTR_USED __attribute__((__used__))
#else
#	define XIEITE_ATTR_USED
#endif

#if XIEITE_HAS_ATTR(__weak__)
#	define XIEITE_ATTR_WEAK __attribute__((__weak__))
#else
#	define XIEITE_ATTR_WEAK
#endif

// https://github.com/isar/libmdbx/blob/master/src/preface.h
// Thanks to eightfold (https://github.com/8ightfold) and Ian Pike (https://github.com/Rinzii) for some original code

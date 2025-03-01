#pragma once

#include "../pp/cplr.hpp"
#include "../pp/hasattr.hpp"
#include "../pp/lang.hpp"

#if X4LANGLEAST(CPP, 2011)
#	define X4ATTR_ALIGN(...) alignas(__VA_ARGS__)
#elif X4LANGLEAST(C, 2011)
#	define X4ATTR_ALIGN(...) _Alignas(__VA_ARGS__)
#elif X4CPLR_MSVC
#	define X4ATTR_ALIGN(...) __declspec(align(__VA_ARGS__))
#elif X4HAS_ATTR(__aligned__)
#	define X4ATTR_ALIGN(...) __attribute__((__aligned__(__VA_ARGS__)))
#else
#	define X4ATTR_ALIGN(...)
#endif

#if X4LANGLEAST(CPP, 2023)
#	define X4ATTR_ASSUME(...) [[assume(__VA_ARGS__)]]
#elif X4CPLRLEAST(GCC, 12, 1)
#	define X4ATTR_ASSUME(...) __attribute__((__assume__(__VA_ARGS__)))
#elif X4CPLRLEAST(CLANG, 4)
#	define X4ATTR_ASSUME(...) __builtin_assume(__VA_ARGS__)
#elif X4CPLR_MSVC
#	define X4ATTR_ASSUME(...) __assume(__VA_ARGS__)
#else
#	define X4ATTR_ASSUME(...) void()
#endif

#if X4HAS_ATTR(__cold__)
#	define X4ATTR_COLD __attribute__((__cold__))
#else
#	define X4ATTR_COLD
#endif

#if X4CPLR_MSVC
#	define X4ATTR_DEPREC __declspec(deprecated)
#elif X4LANGLEAST(CPP, 2014) || X4LANGLEAST(C, 2023)
#	define X4ATTR_DEPREC [[deprecated]]
#elif X4HAS_ATTR(__deprecated__)
#	define X4ATTR_DEPREC __attribute__((__deprecated__))
#else
#	define X4ATTR_DEPREC
#endif

#if X4CPLR_MSVC
#	define X4ATTR_EXPORT __declspec(dllexport)
#elif X4CPLR_GCC || X4CPLR_CLANG
#	define X4ATTR_EXPORT __attribute__((__visibility__("default")))
#else
#	define X4ATTR_EXPORT
#endif

#if X4LANGLEAST(CPP, 2017) || (X4CPLRLEAST(GCC, 8) && X4LANGLEAST(CPP, 2011))
#	define X4ATTR_FALLTHR() [[fallthrough]]
#elif X4CPLRLEAST(GCC, 7) && (!X4CPLR_LCC || ((X4CPLRMAJOR_LCC == 124) && (X4CPLRMINOR_LCC >= 12)) || ((X4CPLRMAJOR_LCC == 125) && (X4CPLRMINOR_LCC >= 5)) || (X4CPLRMAJOR_LCC >= 126))
#	define X4ATTR_FALLTHR() __attribute__((__fallthrough__))
#elif X4CPLR_CLANG && X4LANGLEAST(CPP, 2011)
#	define X4ATTR_FALLTHR() [[clang::fallthrough]]
#elif X4X4CPLR_MSVC
#	define X4ATTR_FALLTHR() __fallthrough
#else
#	define X4ATTR_FALLTHR() void()
#endif

#if X4HAS_ATTR(__flatten__)
#	define X4ATTR_FLAT __attribute__((__flatten__))
#else
#	define X4ATTR_FLAT
#endif

#if X4HAS_ATTR(__always_inline__)
#	define X4ATTR_FORCEINL __attribute__((__always_inline__)) inline
#elif X4CPLR_MSVC
#	define X4ATTR_FORCEINL __forceinline
#else
#	define X4ATTR_FORCEINL inline
#endif

#if X4HAS_ATTR(__hot__)
#	define X4ATTR_HOT __attribute__((__hot__))
#else
#	define X4ATTR_HOT
#endif

#if X4CPLR_MSVC
#	define X4ATTR_IMPORT __declspec(dllimport)
#elif X4CPLR_GCC || X4CPLR_CLANG
#	define X4ATTR_IMPORT __attribute__((__visibility__("default")))
#else
#	define X4ATTR_IMPORT
#endif

#if X4LANGLEAST(CPP, 2020)
#	define X4ATTR_LIKELY [[likely]]
#else
#	define X4ATTR_LIKELY
#endif

#if (X4CPLR_GCC || X4CPLR_CLANG) && !X4CPLR_MSVC
#	define X4ATTR_LOCAL __attribute__((__visibility__("hidden")))
#else
#	define X4ATTR_LOCAL
#endif

#if X4HAS_ATTR(__nodebug__)
#	define X4ATTR_NODEBUG __attribute__((__nodebug__))
#else
#	define X4ATTR_NODEBUG
#endif

#if X4LANGLEAST(CPP, 2017)
#	define X4ATTR_NODISCARD [[nodiscard]]
#elif X4HAS_ATTR(__warn_unused_result__)
#	define X4ATTR_NODISCARD __attribute__((__warn_unused_result__))
#elif X4CPLR_MSVC
#	define X4ATTR_NODISCARD __checkReturn
#else
#	define X4ATTR_NODISCARD
#endif

#if X4LANGLEAST(CPP, 2017)
#	define X4ATTR_NOEX noexcept(true)
#elif X4LANGLEAST(CPP, 2011)
#	define X4ATTR_NOEX throw()
#elif X4HAS_ATTR(__nothrow__)
#	define X4ATTR_NOEX __attribute__((__nothrow__))
#elif X4CPLR_MSVC
#	define X4ATTR_NOEX __declspec(nothrow)
#else
#	define X4ATTR_NOEX
#endif

#if X4HAS_ATTR(__noinline__)
#	define X4ATTR_NOINL __attribute__((__noinline__))
#elif X4CPLR_MSVC
#	define X4ATTR_NOINL __declspec(noinline)
#else
#	define X4ATTR_NOINL
#endif

#if X4HAS_ATTR(__nonnull__)
#	define X4ATTR_NONNULL __attribute__((__nonnull__))
#else
#	define X4ATTR_NONNULL
#endif

#if X4LANGLEAST(CPP, 2011) || X4LANGLEAST(C, 2023)
#	define X4ATTR_NORET [[noreturn]]
#elif X4LANGLEAST(C, 2011)
#	define X4ATTR_NORET _Noreturn
#elif X4HAS_ATTR(__noreturn__)
#	define X4ATTR_NORET __attribute__((__noreturn__))
#else
#	define X4ATTR_NORET
#endif

#if X4CPLRLEAST(MSVC, 16, 9)
#	define X4ATTR_NOUNIQADDR [[msvc::no_unique_address]]
#elif X4LANGLEAST(CPP, 2020)
#	define X4ATTR_NOUNIQADDR [[no_unique_address]]
#else
#	define X4ATTR_NOUNIQADDR
#endif

#if X4CPLR_GCC
#	define X4ATTR_OPTIMIZE(...) __attribute__((__optimize__(__VA_ARGS__)))
#else
#	define X4ATTR_OPTIMIZE(...)
#endif

#if X4HAS_ATTR(__packed__)
#	define X4ATTR_PACK(...) __attribute__((__packed__)) __VA_ARGS__
#elif X4CPLR_MSVC
#	define X4ATTR_PACK(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#else
#	define X4ATTR_PACK(...) __VA_ARGS__
#endif

#if X4HAS_ATTR(__returns_nonnull__)
#	define X4ATTR_RETNONNULL __attribute__((__returns_nonnull__))
#elif X4CPLR_MSVC
#	define X4ATTR_RETNONNULL _Ret_notnull_
#else
#	define X4ATTR_RETNONNULL
#endif

#if X4CPLR_GCC || X4CPLR_CLANG
#	define X4ATTR_SECTION(...) __attribute__((__section__(__VA_ARGS__)))
#elif X4CPLR_MSVC
#	define X4ATTR_SECTION(...) __declspec(allocate(__VA_ARGS__))
#else
#	define X4ATTR_SECTION(...)
#endif

#if X4HAS_ATTR(__stdcall__)
#	define X4ATTR_STDCALL __attribute__((__stdcall__))
#elif X4CPLR_CLANG
#	define X4ATTR_STDCALL __stdcall
#elif X4CPLR_MSVC
#	define X4ATTR_STDCALL __cdecl
#else
#	define X4ATTR_STDCALL
#endif

#if X4CPLR_GCC || X4CPLR_CLANG
#	define X4ATTR_TAIL __attribute__((__musttail__))
#else
#	define X4ATTR_TAIL
#endif

#if X4CPLR_MSVC || X4CPLR_DATALIGHT_C
#	define X4ATTR_THREAD __declspec(thread)
#else
#	define X4ATTR_THREAD
#endif

#if X4LANGLEAST(CPP, 2020)
#	define X4ATTR_UNLIKELY [[unlikely]]
#else
#	define X4ATTR_UNLIKELY
#endif

#if X4LANGLEAST(CPP, 2017)
#	define X4ATTR_UNUSED [[maybe_unused]]
#elif X4HAS_ATTR(__unused__)
#	define X4ATTR_UNUSED __attribute__((__unused__))
#else
#	define X4ATTR_UNUSED
#endif

#if X4HAS_ATTR(__used__)
#	define X4ATTR_USED __attribute__((__used__))
#else
#	define X4ATTR_USED
#endif

#if X4HAS_ATTR(__weak__)
#	define X4ATTR_WEAK __attribute__((__weak__))
#else
#	define X4ATTR_WEAK
#endif

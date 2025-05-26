#ifndef DETAIL_XIEITE_HEADER_PP_ATTR
#	define DETAIL_XIEITE_HEADER_PP_ATTR
#
#	include "../pp/arch.hpp"
#	include "../pp/compiler.hpp"
#	include "../pp/has_attr.hpp"
#	include "../pp/lang.hpp"
#
#	define XIEITE_ATTR_8BITDATA DETAIL_XIEITE_ATTR(eightbit_data)
#
#	define XIEITE_ATTR_ACCESS(...) DETAIL_XIEITE_ATTR(access, (__VA_ARGS__))
#
#	define XIEITE_ATTR_ALIAS(target) DETAIL_XIEITE_ATTR(alias, (#target))
#
#	if XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_ALIGN(alignment) alignas(alignment)
#	elif XIEITE_LANG_VER(C, >=, 2011)
#		define XIEITE_ATTR_ALIGN(alignment) _Alignas(alignment)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_ALIGN(alignment) __declspec(align(alignment))
#	else
#		define XIEITE_ATTR_ALIGN(alignment) DETAIL_XIEITE_ATTR(aligned, (alignment))
#	endif
#
#	define XIEITE_ATTR_ALLOCALIGN(pos) DETAIL_XIEITE_ATTR(alloc_align, (pos))
#
#	define XIEITE_ATTR_ALLOCSIZE(...) DETAIL_XIEITE_ATTR(alloc_size, (__VA_ARGS__))
#
#	define XIEITE_ATTR_ARTIFICIAL DETAIL_XIEITE_ATTR(artificial)
#
#	if XIEITE_LANG_VER(CPP, >=, 2023)
#		define XIEITE_ATTR_ASSUME(...) [[assume(__VA_ARGS__)]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_ASSUME(...) __assume(__VA_ARGS__)
#	elif XIEITE_COMPILER_VER(CLANG, >=, 4)
#		define XIEITE_ATTR_ASSUME(...) __builtin_assume(__VA_ARGS__)
#	elif XIEITE_COMPILER_VER(GCC, >=, 12, 1)
#		define XIEITE_ATTR_ASSUME(...) __attribute__((__assume__(__VA_ARGS__)))
#	else
#		define XIEITE_ATTR_ASSUME(...) void()
#	endif
#
#	define XIEITE_ATTR_ASSUMEALIGN(...) DETAIL_XIEITE_ATTR(assume_aligned, (__VA_ARGS__))
#
#	define XIEITE_ATTR_BANKSWITCH DETAIL_XIEITE_ATTR(bank_switch)
#
#	define XIEITE_ATTR_CALLEEPOPAGGRRET(n) DETAIL_XIEITE_ATTR(callee_pop_aggregate_return, (n))
#
#	define XIEITE_ATTR_CDECL DETAIL_XIEITE_ATTR(cdecl)
#
#	define XIEITE_ATTR_COLD DETAIL_XIEITE_ATTR(cold)
#
#	define XIEITE_ATTR_CONST DETAIL_XIEITE_ATTR(const)
#
#	define XIEITE_ATTR_COPY(...) DETAIL_XIEITE_ATTR(copy, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_CSTR(...) DETAIL_XIEITE_ATTR(null_terminated_string_arg, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_CTOR(...) DETAIL_XIEITE_ATTR(constructor, __VA_OPT__((__VA_ARGS__)))
#
#	if XIEITE_LANG_VER(CPP, >=, 2014) || XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_DEPREC(...) [[deprecated __VA_OPT__((__VA_ARGS__))]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_DEPREC(...) __declspec(deprecated __VA_OPT__((__VA_ARGS__)))
#	else
#		define XIEITE_ATTR_DEPREC(...) DETAIL_XIEITE_ATTR(deprecated, __VA_OPT__((__VA_ARGS__)))
#	endif
#
#	define XIEITE_ATTR_DISINTERRUPT DETAIL_XIEITE_ATTR(disinterrupt)
#
#	define XIEITE_ATTR_DTOR(...) DETAIL_XIEITE_ATTR(destructor, __VA_OPT__((__VA_ARGS__)))
#
#	ifdef XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_EMPTY_BASES __declspec(empty_bases)
#	else
#		define XIEITE_ATTR_EMPTY_BASES
#	endif
#
#	define XIEITE_ATTR_ERROR(msg) DETAIL_XIEITE_ATTR(error, (msg))
#
#	define XIEITE_ATTR_EXHANDLER DETAIL_XIEITE_ATTR(exception_handler)
#
#	define XIEITE_ATTR_EXPECTTHROW DETAIL_XIEITE_ATTR(expected_throw)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_EXPORT __declspec(dllexport)
#	else
#		define XIEITE_ATTR_EXPORT DETAIL_XIEITE_ATTR(__dllexport__)
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017) || XIEITE_LANG_VER(C, >=, 2023) || (XIEITE_COMPILER_VER(GCC, >=, 8) && XIEITE_LANG_VER(CPP, >=, 2011))
#		define XIEITE_ATTR_FALLTHR() [[fallthrough]]
#	elif XIEITE_COMPILER_TYPE_CLANG && XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_FALLTHR() [[clang::fallthrough]]
#	elif XIEITE_COMPILER_VER(GCC, >=, 7) || XIEITE_COMPILER_VER(LLC, >=, 125, 5) || (XIEITE_COMPILER_VER(LLC, <, 125) && XIEITE_COMPILER_VER(LLC, >=, 124, 12))
#		define XIEITE_ATTR_FALLTHR() __attribute__((__fallthrough__))
#	elif XIEITE_XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FALLTHR() __fallthrough
#	else
#		define XIEITE_ATTR_FALLTHR() void()
#	endif
#
#	define XIEITE_ATTR_FAR DETAIL_XIEITE_ATTR(far)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FASTCALL __fastcall
#	else
#		define XIEITE_ATTR_FASTCALL DETAIL_XIEITE_ATTR(fastcall)
#	endif
#
#	define XIEITE_ATTR_FASTINTERRUPT DETAIL_XIEITE_ATTR(fast_interrupt)
#
#	define XIEITE_ATTR_FD(...) DETAIL_XIEITE_ATTR(fd_arg, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_FD_READ(...) DETAIL_XIEITE_ATTR(fd_arg_read, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_FD_WRITE(...) DETAIL_XIEITE_ATTR(fd_arg_write, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_FLAT DETAIL_XIEITE_ATTR(flatten)
#
#	define XIEITE_ATTR_FORCEALIGNARGPTR DETAIL_XIEITE_ATTR(force_align_arg_pointer)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FORCEINL [[msvc::forceinline]]
#	else
#		define XIEITE_ATTR_FORCEINL DETAIL_XIEITE_ATTR(always_inline)
#	endif
#
#	define XIEITE_ATTR_FMT(...) DETAIL_XIEITE_ATTR(format, (__VA_ARGS__))
#
#	define XIEITE_ATTR_FMTARG(idx) DETAIL_XIEITE_ATTR(format_arg, (idx))
#
#	define XIEITE_ATTR_GNUINL DETAIL_XIEITE_ATTR(gnu_inline)
#
#	define XIEITE_ATTR_HOT DETAIL_XIEITE_ATTR(hot)
#
#	define XIEITE_ATTR_IFUNC(resolver) DETAIL_XIEITE_ATTR(ifunc, (resolver))
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_IMPORT __declspec(dllimport)
#	else
#		define XIEITE_ATTR_IMPORT DETAIL_XIEITE_ATTR(__dllimport__)
#	endif
#
#	define XIEITE_ATTR_INTERNAL DETAIL_XIEITE_ATTR(visibility, ("internal"))
#
#	define XIEITE_ATTR_INTERRUPT DETAIL_XIEITE_ATTR(interrupt)
#
#	define XIEITE_ATTR_INTERRUPTHANDLER DETAIL_XIEITE_ATTR(interrupt_handler)
#
#	define XIEITE_ATTR_ISR DETAIL_XIEITE_ATTR(isr)
#
#	define XIEITE_ATTR_KSPISUSP DETAIL_XIEITE_ATTR(kspisusp)
#
#	define XIEITE_ATTR_LEAF DETAIL_XIEITE_ATTR(leaf)
#
#	if XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_LIKELY [[likely]]
#	else
#		define XIEITE_ATTR_LIKELY
#	endif
#
#	define XIEITE_ATTR_LOCAL DETAIL_XIEITE_ATTR(visibility, ("hidden"))
#
#	if XIEITE_ARCH_TYPE_BLACKFIN || XIEITE_ARCH_TYPE_POWERPC || XIEITE_ARCH_TYPE_RS_6000
#		define XIEITE_ATTR_LONGCALL DETAIL_XIEITE_ATTR(longcall)
#	else
#		define XIEITE_ATTR_LONGCALL DETAIL_XIEITE_ATTR(long_call)
#	endif
#
#	define XIEITE_ATTR_MALLOC(...) DETAIL_XIEITE_ATTR(malloc, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_MIPS16 DETAIL_XIEITE_ATTR(mips16)
#
#	define XIEITE_ATTR_MODEL(name) DETAIL_XIEITE_ATTR(model_name, (name))
#
#	define XIEITE_ATTR_MSABI DETAIL_XIEITE_ATTR(ms_abi)
#
#	define XIEITE_ATTR_MSHOOKPROLOGUE DETAIL_XIEITE_ATTR(ms_hook_prologue)
#
#	define XIEITE_ATTR_MUSTTAIL DETAIL_XIEITE_ATTR(musttail)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NAKED __declspec(naked)
#	else
#		define XIEITE_ATTR_NAKED DETAIL_XIEITE_ATTR(naked)
#	endif
#
#	define XIEITE_ATTR_NEAR DETAIL_XIEITE_ATTR(near)
#
#	define XIEITE_ATTR_NEST DETAIL_XIEITE_ATTR(nesting)
#
#	define XIEITE_ATTR_NMIHANDLER DETAIL_XIEITE_ATTR(nmi_handler)
#
#	define XIEITE_ATTR_NOCLONE DETAIL_XIEITE_ATTR(noclone)
#
#	if XIEITE_HAS_ATTR(__nodebug__)
#		define XIEITE_ATTR_NODEBUG __attribute__((__nodebug__))
#	else
#		define XIEITE_ATTR_NODEBUG
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_NODISCARD [[nodiscard]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NODISCARD __checkReturn
#	else
#		define XIEITE_ATTR_NODISCARD DETAIL_XIEITE_ATTR(warn_unused_result)
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_NOEX noexcept(true)
#	elif XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_NOEX throw()
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NOEX __declspec(nothrow)
#	elif XIEITE_HAS_ATTR(__nothrow__)
#		define XIEITE_ATTR_NOEX __attribute__((__nothrow__))
#	else
#		define XIEITE_ATTR_NOEX
#	endif
#
#	define XIEITE_ATTR_NOICF DETAIL_XIEITE_ATTR(no_icf)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NOINL __declspec(noinline)
#	else
#		define XIEITE_ATTR_NOINL DETAIL_XIEITE_ATTR(noinline)
#	endif
#
#	define XIEITE_ATTR_NOINSTRM DETAIL_XIEITE_ATTR(no_instrument_function)
#
#	define XIEITE_ATTR_NOIPA DETAIL_XIEITE_ATTR(noipa)
#
#	define XIEITE_ATTR_NOMIPS16 DETAIL_XIEITE_ATTR(nomips16)
#
#	define XIEITE_ATTR_NONNULL(...) DETAIL_XIEITE_ATTR(nunnull, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_NONNULLIFNONZERO(...) DETAIL_XIEITE_ATTR(nonnull_if_nonzero, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_NOPLT DETAIL_XIEITE_ATTR(noplt)
#
#	define XIEITE_ATTR_NOPROFILEINSTRM DETAIL_XIEITE_ATTR(no_profile_instrument_function)
#
#	define XIEITE_ATTR_NOREORD DETAIL_XIEITE_ATTR(no_reorder)
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
#	define XIEITE_ATTR_NOSAN(...) DETAIL_XIEITE_ATTR(no_sanitize, (__VA_ARGS__))
#
#	if XIEITE_COMPILER_VER(GCC, >=, 4, 8)
#		define XIEITE_ATTR_NOSANADDR DETAIL_XIEITE_ATTR(no_sanitize_address)
#	else
#		define XIEITE_ATTR_NOSANADDR __attribute__((__no_address_safety_analysis__))
#	endif
#
#	define XIEITE_ATTR_NOSANCOVER DETAIL_XIEITE_ATTR(no_sanitize_coverage)
#
#	define XIEITE_ATTR_NOSANTHREAD DETAIL_XIEITE_ATTR(no_sanitize_thread)
#
#	define XIEITE_ATTR_NOSANUNDEF DETAIL_XIEITE_ATTR(no_sanitize_undefined)
#
#	define XIEITE_ATTR_NOSTACKLIMIT DETAIL_XIEITE_ATTR(no_stack_limit)
#
#	define XIEITE_ATTR_NOSTACKPROT DETAIL_XIEITE_ATTR(no_stack_protector)
#
#	define XIEITE_ATTR_NOSTACKSPLIT DETAIL_XIEITE_ATTR(no_split_stack)
#
#	if XIEITE_COMPILER_VER(MSVC, >=, 16, 9)
#		define XIEITE_ATTR_NOUNIQADDR [[msvc::no_unique_address]]
#	elif XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_NOUNIQADDR [[no_unique_address]]
#	else
#		define XIEITE_ATTR_NOUNIQADDR
#	endif
#
#	define XIEITE_ATTR_OPTIMIZE(...) DETAIL_XIEITE_ATTR(optimize, (__VA_ARGS__))
#
#	define XIEITE_ATTR_OSMAIN DETAIL_XIEITE_ATTR(OS_main)
#
#	define XIEITE_ATTR_OSTASK DETAIL_XIEITE_ATTR(OS_task)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_PACK(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#	else
#		define XIEITE_ATTR_PACK(...) DETAIL_XIEITE_ATTR(packed) __VA_ARGS__
#	endif
#
#	define XIEITE_ATTR_PATCH DETAIL_XIEITE_ATTR(patchable_function_entry)
#
#	define XIEITE_ATTR_PCS DETAIL_XIEITE_ATTR(pcs)
#
#	define XIEITE_ATTR_PROT DETAIL_XIEITE_ATTR(visibility, ("protected"))
#
#	define XIEITE_ATTR_PURE DETAIL_XIEITE_ATTR(pure)
#
#	define XIEITE_ATTR_REGPARAM(n) DETAIL_XIEITE_ATTR(regparm, (n))
#
#	if XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_REPRO [[reproducible]]
#	else
#		define XIEITE_ATTR_REPRO DETAIL_XIEITE_ATTR(reproducible)
#	endif
#
#	define XIEITE_ATTR_RESBANK DETAIL_XIEITE_ATTR(resbank)
#
#	define XIEITE_ATTR_RETAIN DETAIL_XIEITE_ATTR(retain)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_RETNONNULL _Ret_notnull_
#	else
#		define XIEITE_ATTR_RETNONNULL DETAIL_XIEITE_ATTR(returns_nonnull)
#	endif
#
#	define XIEITE_ATTR_RETTWICE DETAIL_XIEITE_ATTR(returns_twice)
#
#	define XIEITE_ATTR_SAVEALL DETAIL_XIEITE_ATTR(saveall)
#
#	define XIEITE_ATTR_SAVEVOLATILE DETAIL_XIEITE_ATTR(save_volatiles)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_SECTION(name) __declspec(allocate(name))
#	else
#		define XIEITE_ATTR_SECTION(name) DETAIL_XIEITE_ATTR(section, (name))
#	endif
#
#	define XIEITE_ATTR_SENTINEL(...) DETAIL_XIEITE_ATTR(sentinel, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_SIGNAL DETAIL_XIEITE_ATTR(signal)
#
#	if XIEITE_ARCH_TYPE_BLACKFIN || XIEITE_ARCH_TYPE_POWERPC || XIEITE_ARCH_TYPE_RS_6000
#		define XIEITE_ATTR_SHORTCALL DETAIL_XIEITE_ATTR(shortcall)
#	else
#		define XIEITE_ATTR_SHORTCALL DETAIL_XIEITE_ATTR(short_call)
#	endif
#
#	define XIEITE_ATTR_SIMD(...) DETAIL_XIEITE_ATTR(simd, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_SPSWITCH DETAIL_XIEITE_ATTR(sp_switch)
#
#	define XIEITE_ATTR_SSEREGPARAM(n) DETAIL_XIEITE_ATTR(sseregparm, (n))
#
#	define XIEITE_ATTR_STACKPROT DETAIL_XIEITE_ATTR(stack_protect)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_STDCALL __cdecl
#	elif XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_STDCALL __stdcall
#	else
#		define XIEITE_ATTR_STDCALL DETAIL_XIEITE_ATTR(stdcall)
#	endif
#
#	define XIEITE_ATTR_SYMVER(ver) DETAIL_XIEITE_ATTR(symver, (ver))
#
#	define XIEITE_ATTR_SYSCALLLINK DETAIL_XIEITE_ATTR(syscall_linkage)
#
#	define XIEITE_ATTR_SYSVABI DETAIL_XIEITE_ATTR(sysv_abi)
#
#	define XIEITE_ATTR_TAINT DETAIL_XIEITE_ATTR(tainted_args)
#
#	define XIEITE_ATTR_TARGET(...) DETAIL_XIEITE_ATTR(target, (__VA_ARGS__))
#
#	define XIEITE_ATTR_TARGETCLONES(...) DETAIL_XIEITE_ATTR(target_clones, (__VA_ARGS__))
#
#	define XIEITE_ATTR_TINYDATA DETAIL_XIEITE_ATTR(tiny_data)
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_THISCALL __thiscall
#	else
#		define XIEITE_ATTR_THISCALL DETAIL_XIEITE_ATTR(thiscall)
#	endif
#
#	if XIEITE_COMPILER_TYPE_MSVC || XIEITE_COMPILER_TYPE_DATALIGHT_C
#		define XIEITE_ATTR_THREAD __declspec(thread)
#	else
#		define XIEITE_ATTR_THREAD
#	endif
#
#	define XIEITE_ATTR_THREADINTERRUPT DETAIL_XIEITE_ATTR(interrupt_thread)
#
#	define XIEITE_ATTR_TRAP DETAIL_XIEITE_ATTR(trap_exit)
#
#	define XIEITE_ATTR_UNAVAIL DETAIL_XIEITE_ATTR(unavailable)
#
#	if XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_UNLIKELY [[unlikely]]
#	else
#		define XIEITE_ATTR_UNLIKELY
#	endif
#
#	if XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_UNSEQ [[unsequenced]]
#	else
#		define XIEITE_ATTR_UNSEQ DETAIL_XIEITE_ATTR(unsequenced)
#	endif
#
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_UNUSED [[maybe_unused]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_UNUSED __pragma(warning(suppress: 4100 4101 4505))
#	else
#		define XIEITE_ATTR_UNUSED DETAIL_XIEITE_ATTR(unused)
#	endif
#
#	define XIEITE_ATTR_USED DETAIL_XIEITE_ATTR(used)
#
#	define XIEITE_ATTR_VEC DETAIL_XIEITE_ATTR(function_vector)
#
#	define XIEITE_ATTR_VER(id) DETAIL_XIEITE_ATTR(version_id, (id))
#
#	define XIEITE_ATTR_VISIBLE DETAIL_XIEITE_ATTR(externally_visible)
#
#	define XIEITE_ATTR_VLIW DETAIL_XIEITE_ATTR(vliw)
#
#	define XIEITE_ATTR_WARN(msg) DETAIL_XIEITE_ATTR(warning, (msg))
#
#	define XIEITE_ATTR_WEAK DETAIL_XIEITE_ATTR(weak)
#
#	define XIEITE_ATTR_WEAKREF(...) DETAIL_XIEITE_ATTR(weakref, __VA_OPT__((__VA_ARGS__)))
#
#	define XIEITE_ATTR_ZEROREGS(choice) DETAIL_XIEITE_ATTR(zero_call_used_regs, (choice))
#
#	if XIEITE_COMPILER_TYPE_GCC && (XIEITE_LANG_VER(CPP, >=, 2011) || XIEITE_LANG_VER(C, >=, 2023))
#		define DETAIL_XIEITE_ATTR(attr, ...) [[gnu::attr __VA_ARGS__]]
#	else
#		include "../pp/if.hpp"
#		define DETAIL_XIEITE_ATTR(attr, ...) XIEITE_IF(XIEITE_HAS_ATTR(__##attr##__))(__attribute__((__##attr##__ __VA_ARGS__)))()
#	endif
#endif

// https://gcc.gnu.org/onlinedocs/gcc/Function-Attributes.html
// https://github.com/isar/libmdbx/blob/master/src/preface.h
// Thanks to eightfold (https://github.com/8ightfold) and Ian Pike (https://github.com/Rinzii) for some original code

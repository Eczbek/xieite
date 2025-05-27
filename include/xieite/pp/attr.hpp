#ifndef DETAIL_XIEITE_HEADER_PP_ATTR
#	define DETAIL_XIEITE_HEADER_PP_ATTR
#
#	include "../pp/and.hpp"
#	include "../pp/any.hpp"
#	include "../pp/arch.hpp"
#	include "../pp/compiler.hpp"
#	include "../pp/has_attr.hpp"
#	include "../pp/has_declspec.hpp"
#	include "../pp/if.hpp"
#	include "../pp/lang.hpp"
#	include "../pp/none.hpp"
#	include "../pp/or.hpp"
#	include "../pp/pragma.hpp"
#
#	define XIEITE_ATTR_8_BIT_DATA DETAIL_XIEITE_ATTR(GCC, gnu, eightbit_data)
#	define XIEITE_ATTR_AARCH64_SVE_PCS DETAIL_XIEITE_ATTR(CLANG, clang, aarch64_sve_pcs)
#	define XIEITE_ATTR_AARCH64_VEC_PCS DETAIL_XIEITE_ATTR(CLANG, clang, aarch64_vector_pcs)
#	define XIEITE_ATTR_ABI_TAG DETAIL_XIEITE_ATTR(GCC, gnu, abi_tag)
#	define XIEITE_ATTR_ACCESS(...) DETAIL_XIEITE_ATTR(GCC, gnu, access, (__VA_ARGS__))
#	define XIEITE_ATTR_ACQUIRE_AFTER(...) DETAIL_XIEITE_ATTR(,, acquire_after, (__VA_ARGS__))
#	define XIEITE_ATTR_ACQUIRE_BEFORE(...) DETAIL_XIEITE_ATTR(,, acquire_before, (__VA_ARGS__))
#	define XIEITE_ATTR_ACQUIRE_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, acquire_capability)
#	define XIEITE_ATTR_ACQUIRE_HANDLE(handle) DETAIL_XIEITE_ATTR(CLANG, clang, acquire_handle, (handle))
#	define XIEITE_ATTR_ACQUIRE_SHARED_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, acquire_shared_capability)
#	define XIEITE_ATTR_ADDR_SPACE(...) DETAIL_XIEITE_ATTR(CLANG, clang, address_space, (__VA_ARGS__))
#	define XIEITE_ATTR_ALIAS(target) DETAIL_XIEITE_ATTR(GCC, gnu, alias, (#target))
#	if XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_ALIGN(...) alignas(__VA_ARGS__)
#	elif XIEITE_LANG_VER(C, >=, 2011)
#		define XIEITE_ATTR_ALIGN(...) _Alignas(__VA_ARGS__)
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_ALIGN(...) __declspec(align(__VA_ARGS__))
#	else
#		define XIEITE_ATTR_ALIGN(...) DETAIL_XIEITE_ATTR(GCC, gnu, aligned, (__VA_ARGS__))
#	endif
#	define XIEITE_ATTR_ALIGN_VALUE(...) DETAIL_XIEITE_ATTR(,, align_value, (__VA_ARGS__))
#	define XIEITE_ATTR_ALLOCATING DETAIL_XIEITE_ATTR(CLANG, clang, allocating)
#	define XIEITE_ATTR_ALLOCATOR DETAIL_XIEITE_ATTR(,, allocator)
#	define XIEITE_ATTR_ALLOC_ALIGN(pos) DETAIL_XIEITE_ATTR(GCC, gnu, alloc_align, (pos))
#	define XIEITE_ATTR_ALLOC_SIZE(...) DETAIL_XIEITE_ATTR(GCC, gnu, alloc_size, (__VA_ARGS__))
#	define XIEITE_ATTR_ALWAYS_DESTROY DETAIL_XIEITE_ATTR(CLANG, clang, always_destroy)
#	define XIEITE_ATTR_ANNOTATE(...) DETAIL_XIEITE_ATTR(CLANG, clang, annotate, (__VA_ARGS__))
#	define XIEITE_ATTR_ANNOTATE_TYPE(...) DETAIL_XIEITE_ATTR(CLANG, clang, annotate_type, (__VA_ARGS__))
#	define XIEITE_ATTR_ARC_WEAK_REF_UNAVAIL DETAIL_XIEITE_ATTR(CLANG, clang, objc_arc_weak_reference_unavailable)
#	define XIEITE_ATTR_ARG_WITH_TYPE_TAG(...) DETAIL_XIEITE_ATTR(CLANG, clang, argument_with_type_tag, (__VA_ARGS__))
#	define XIEITE_ATTR_ARM_MVE_STRICT_POLYMORPHISM DETAIL_XIEITE_ATTR(CLANG, clang, __clang_arm_mve_strict_polymorphism)
#	define XIEITE_ATTR_ARM_SVE_VEC_BITS(...) DETAIL_XIEITE_ATTR(,, arm_sve_vector_bits, (__VA_ARGS__))
#	define XIEITE_ATTR_ARTIFICIAL DETAIL_XIEITE_ATTR(GCC, gnu, artificial)
#	define XIEITE_ATTR_ASM(...) DETAIL_XIEITE_ATTR(CLANG,, asm, (__VA_ARGS__))
#	if XIEITE_LANG_VER(CPP, >=, 2023)
#		define XIEITE_ATTR_ASSUME(...) [[assume(__VA_ARGS__)]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_ASSUME(...) __assume(__VA_ARGS__)
#	elif XIEITE_COMPILER_VER(CLANG, >=, 4)
#		define XIEITE_ATTR_ASSUME(...) __builtin_assume(__VA_ARGS__)
#	elif XIEITE_COMPILER_VER(GCC, >=, 12, 1)
#		define XIEITE_ATTR_ASSUME(...) __attribute__((assume(__VA_ARGS__)))
#	else
#		define XIEITE_ATTR_ASSUME(...) void()
#	endif
#	define XIEITE_ATTR_ASSERT_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, assert_capability)
#	define XIEITE_ATTR_ASSERT_EXCLUSIVE_LOCK DETAIL_XIEITE_ATTR(,, assert_exclusive_lock)
#	define XIEITE_ATTR_ASSERT_SHARED_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, assert_shared_capability)
#	define XIEITE_ATTR_ASSERT_SHARED_LOCK DETAIL_XIEITE_ATTR(,, assert_shared_lock)
#	define XIEITE_ATTR_ASSUME_ALIGN(...) DETAIL_XIEITE_ATTR(GCC, gnu, assume_aligned, (__VA_ARGS__))
#	define XIEITE_ATTR_ATOMIC DETAIL_XIEITE_ATTR(CLANG, clang, atomic)
#	define XIEITE_ATTR_AVAIL(...) DETAIL_XIEITE_ATTR(CLANG, clang, availability, (__VA_ARGS__))
#	define XIEITE_ATTR_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD DETAIL_XIEITE_ATTR(CLANG, clang, available_only_in_default_eval_method)
#	define XIEITE_ATTR_BANK_SWITCH DETAIL_XIEITE_ATTR(GCC, gnu, bank_switch)
#	define XIEITE_ATTR_BLOCKING DETAIL_XIEITE_ATTR(CLANG, clang, blocking)
#	define XIEITE_ATTR_BLOCKS DETAIL_XIEITE_ATTR(CLANG, clang, blocks)
#	define XIEITE_ATTR_BOXABLE DETAIL_XIEITE_ATTR(CLANG, clang, objc_boxable)
#	define XIEITE_ATTR_BPF_FAST_CALL DETAIL_XIEITE_ATTR(CLANG, clang, bpf_fastcall)
#	define XIEITE_ATTR_BPF_TYPE_TAG(str) DETAIL_XIEITE_ATTR(CLANG, clang, bpf_type_tag, (str))
#	define XIEITE_ATTR_BRIDGE DETAIL_XIEITE_ATTR(CLANG, clang, objc_bridge)
#	define XIEITE_ATTR_BRIDGE_MUT DETAIL_XIEITE_ATTR(CLANG, clang, objc_bridge_mutable)
#	define XIEITE_ATTR_BRIDGE_RELATED DETAIL_XIEITE_ATTR(CLANG, clang, objc_bridge_related)
#	define XIEITE_ATTR_BTF_DECL_TAG(str) DETAIL_XIEITE_ATTR(CLANG, clang, btf_decl_tag, (str))
#	if XIEITE_ARCH_TYPE_AARCH32
#		define XIEITE_ATTR_BUILTIN_ALIAS(...) DETAIL_XIEITE_ATTR(CLANG, clang, __clang_arm_builtin_alias, (__VA_ARGS__))
#	else
#		define XIEITE_ATTR_BUILTIN_ALIAS(...) DETAIL_XIEITE_ATTR(CLANG, clang, builtin_alias, (__VA_ARGS__))
#	endif
#	define XIEITE_ATTR_CALLABLE_WHEN(...) DETAIL_XIEITE_ATTR(CLANG, clang, callable_when, (__VA_ARGS__))
#	define XIEITE_ATTR_CALLBACK(...) DETAIL_XIEITE_ATTR(CLANG, clang, callback, (__VA_ARGS__))
#	define XIEITE_ATTR_CALLED_ONCE DETAIL_XIEITE_ATTR(CLANG, clang, called_once)
#	define XIEITE_ATTR_CAPABILITY(...) DETAIL_XIEITE_ATTR(CLANG, clang, capability)
#	define XIEITE_ATTR_CALLEE_POP_AGGREGATE_RET(...) DETAIL_XIEITE_ATTR(GCC, gnu, callee_pop_aggregate_return, (__VA_ARGS__))
#	define XIEITE_ATTR_CARRIES_DEPENDENCY DETAIL_XIEITE_ATTR(,, carries_dependency)
#	define XIEITE_ATTR_CDECL DETAIL_XIEITE_ATTR(GCC, gnu, cdecl)
#	define XIEITE_ATTR_CF_AUDITED_TRANSFER DETAIL_XIEITE_ATTR(CLANG, clang, cf_audited_transfer)
#	define XIEITE_ATTR_CF_CONSUMED DETAIL_XIEITE_ATTR(CLANG, clang, cf_consumed)
#	define XIEITE_ATTR_CF_RETURN_RETAIN DETAIL_XIEITE_ATTR(CLANG, clang, fg_returns_retained)
#	define XIEITE_ATTR_CF_UNKNOWN_TRANSFER DETAIL_XIEITE_ATTR(CLANG, clang, cf_unknown_transfer)
#	define XIEITE_ATTR_CFI_CANON_JUMP_TABLE DETAIL_XIEITE_ATTR(CLANG, clang, cfi_canonical_jump_table)
#	define XIEITE_ATTR_CLASS_STUB DETAIL_XIEITE_ATTR(CLANG, clang, objc_class_stub)
#	define XIEITE_ATTR_CLEANUP(...) DETAIL_XIEITE_ATTR(GCC, gnu, cleanup, (__VA_ARGS__))
#	define XIEITE_ATTR_CLSPV_LIBCLC_BUILTIN DETAIL_XIEITE_ATTR(CLANG, clang, clspv_libclc_builtin)
#	define XIEITE_ATTR_CMSE_NONSECURE_CALL DETAIL_XIEITE_ATTR(,, cmse_nonsecure_call)
#	define XIEITE_ATTR_CMSE_NONSECURE_ENTRY DETAIL_XIEITE_ATTR(,, cmse_nonsecure_entry)
#	define XIEITE_ATTR_CO_AWAIT_ELIDABLE DETAIL_XIEITE_ATTR(CLANG, clang, coro_await_elidable)
#	define XIEITE_ATTR_CO_AWAIT_ELIDABLE_ARG DETAIL_XIEITE_ATTR(CLANG, clang, coro_await_elidable_argument)
#	define XIEITE_ATTR_CO_LIFETIME_BOUND DETAIL_XIEITE_ATTR(CLANG, clang, coro_liftimebound)
#	define XIEITE_ATTR_CO_ONLY_DESTROY_WHEN_COMPLETE DETAIL_XIEITE_ATTR(CLANG, clang, coro_only_destroy_when_complete)
#	define XIEITE_ATTR_CO_RETURN_TYPE DETAIL_XIEITE_ATTR(CLANG, clang, coro_return_type)
#	define XIEITE_ATTR_CO_WRAPPER DETAIL_XIEITE_ATTR(CLANG, clang, coro_wrapper)
#	define XIEITE_ATTR_CODE_ALIGN(...) DETAIL_XIEITE_ATTR(CLANG, clang, code_align, (__VA_ARGS__))
#	define XIEITE_ATTR_CODE_SEG DETAIL_XIEITE_ATTR(,, code_seg)
#	define XIEITE_ATTR_COLD DETAIL_XIEITE_ATTR(GCC, gnu, cold)
#	define XIEITE_ATTR_COMMON DETAIL_XIEITE_ATTR(GCC, gnu, common)
#	define XIEITE_ATTR_CONST DETAIL_XIEITE_ATTR(GCC, gnu, const)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_CONSTEXPR [[msvc::constexpr]]
#	else
#		define XIEITE_ATTR_CONSTEXPR
#	endif
#	if XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_CONSTINIT constinit
#	else
#		define XIEITE_ATTR_CONSTINIT DETAIL_XIEITE_ATTR(CLANG, clang, require_constant_initialization)
#	endif
#	define XIEITE_ATTR_CONSUMABLE DETAIL_XIEITE_ATTR(CLANG, clang, consumable)
#	define XIEITE_ATTR_CONSUMABLE_AUTO_CAST_STATE DETAIL_XIEITE_ATTR(CLANG, clang, consumable_auto_cast_state)
#	define XIEITE_ATTR_CONSUMABLE_SET_STATE_ON_READ DETAIL_XIEITE_ATTR(CLANG, clang, consumable_set_state_on_read)
#	define XIEITE_ATTR_CONVERGENT DETAIL_XIEITE_ATTR(CLANG, clang, convergent)
#	define XIEITE_ATTR_COPY(...) DETAIL_XIEITE_ATTR(GCC, gnu, copy, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_COUNTED_BY(...) DETAIL_XIEITE_ATTR(CLANG, clang, counted_by, (__VA_ARGS__))
#	define XIEITE_ATTR_COUNTED_BY_OR_NULL(...) DETAIL_XIEITE_ATTR(CLANG, clang, counted_by_or_null, (__VA_ARGS__))
#	define XIEITE_ATTR_CPU_DISPATCH(...) DETAIL_XIEITE_ATTR(CLANG, clang, cpu_dispatch, (__VA_ARGS__))
#	define XIEITE_ATTR_CPU_SPECIFIC(...) DETAIL_XIEITE_ATTR(CLANG, clang, cpu_specific, (__VA_ARGS__))
#	define XIEITE_ATTR_CTOR(...) DETAIL_XIEITE_ATTR(GCC, gnu, constructor, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_DECLARE_SIMD XIEITE_PRAGMA_CLANG(omp declare simd)
#	define XIEITE_ATTR_DECLARE_TARGET XIEITE_PRAGMA_CLANG(omp declare target)
#	define XIEITE_ATTR_DECLARE_VARIANT XIEITE_PRAGMA_CLANG(omp declare variant)
#	if XIEITE_LANG_VER(CPP, >=, 2014) || XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_DEPRECATED(...) [[deprecated __VA_OPT__((__VA_ARGS__))]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_DEPRECATED(...) __declspec(deprecated __VA_OPT__((__VA_ARGS__)))
#	else
#		define XIEITE_ATTR_DEPRECATED(...) DETAIL_XIEITE_ATTR(GCC, gnu, deprecated, __VA_OPT__((__VA_ARGS__)))
#	endif
#	define XIEITE_ATTR_DESIGNATED_INIT DETAIL_XIEITE_ATTR(CLANG, clang, objc_designated_initializer)
#	define XIEITE_ATTR_DEVICE DETAIL_XIEITE_ATTR(,, device)
#	define XIEITE_ATTR_DEVICE_BUILTIN_SURFACE DETAIL_XIEITE_ATTR(,, device_builtin_surface_type)
#	define XIEITE_ATTR_DEVICE_BUILTIN_TEXTURE DETAIL_XIEITE_ATTR(,, device_builtin_texture_type)
#	define XIEITE_ATTR_DIAGNOSE_AS_BUILTIN(...) DETAIL_XIEITE_ATTR(CLANG, clang, diagnose_as_builtin, (__VA_ARGS__))
#	define XIEITE_ATTR_DIAGNOSE_IF(...) DETAIL_XIEITE_ATTR(,, diagnose_if, (__VA_ARGS__))
#	define XIEITE_ATTR_DIRECT DETAIL_XIEITE_ATTR(CLANG, clang, objc_direct)
#	define XIEITE_ATTR_DIRECT_MEMBERS DETAIL_XIEITE_ATTR(CLANG, clang, objc_direct_members)
#	define XIEITE_ATTR_DISINTERRUPT DETAIL_XIEITE_ATTR(GCC, gnu, disinterrupt)
#	define XIEITE_ATTR_DTOR(...) DETAIL_XIEITE_ATTR(GCC, gnu, destructor, __VA_OPT__((__VA_ARGS__)))
#	ifdef XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_EMPTY_BASES __declspec(empty_bases)
#	else
#		define XIEITE_ATTR_EMPTY_BASES
#	endif
#	define XIEITE_ATTR_ENABLE_IF(...) DETAIL_XIEITE_ATTR(,, enable_if, (__VA_ARGS__))
#	define XIEITE_ATTR_ENFORCE_READ_ONLY_PLACEMENT DETAIL_XIEITE_ATTR(CLANG, clang, enforce_read_only_placement)
#	define XIEITE_ATTR_ENFORCE_TCB(name) DETAIL_XIEITE_ATTR(CLANG, clang, enforce_tcb, (name))
#	define XIEITE_ATTR_ENFORCE_TCB_LEAF(name) DETAIL_XIEITE_ATTR(CLANG, clang, enforce_tcb_leaf, (name))
#	define XIEITE_ATTR_ENUM_EXT(kind) DETAIL_XIEITE_ATTR(CLANG, clang, enum_extensibility, (kind))
#	define XIEITE_ATTR_ERROR(msg) DETAIL_XIEITE_ATTR(GCC, gnu, error, (msg))
#	define XIEITE_ATTR_EXCEPT DETAIL_XIEITE_ATTR(CLANG, clang, objc_exception)
#	define XIEITE_ATTR_EXCEPT_HANDLER DETAIL_XIEITE_ATTR(GCC, gnu, exception_handler)
#	define XIEITE_ATTR_EXCLUDE_LOCK DETAIL_XIEITE_ATTR(,, locks_excluded)
#	define XIEITE_ATTR_EXCLUSIVE_LOCK DETAIL_XIEITE_ATTR(,, exclusive_lock_function)
#	define XIEITE_ATTR_EXPECT_EXCEPT DETAIL_XIEITE_ATTR(GCC, gnu, expected_throw)
#	define XIEITE_ATTR_EXPLICIT_INIT DETAIL_XIEITE_ATTR(CLANG, clang, require_explicit_initialization)
#	define XIEITE_ATTR_EXPORT_NAME(name) DETAIL_XIEITE_ATTR(CLANG, clang, export_name, (name))
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_EXPORT __declspec(dllexport)
#	else
#		define XIEITE_ATTR_EXPORT DETAIL_XIEITE_ATTR(GCC, gnu, dllexport)
#	endif
#	define XIEITE_ATTR_EXT_VEC_TYPE(...) DETAIL_XIEITE_ATTR(CLANG, clang, ext_vector_type, (__VA_ARGS__))
#	define XIEITE_ATTR_EXTERN_RETAIN DETAIL_XIEITE_ATTR(CLANG, clang, objc_externally_retained)
#	define XIEITE_ATTR_EXTERN_SYMBOL(...) DETAIL_XIEITE_ATTR(CLANG, clang, external_source_symbol, (__VA_ARGS__))
#	if XIEITE_LANG_VER(CPP, >=, 2017) || XIEITE_LANG_VER(C, >=, 2023) || (XIEITE_COMPILER_VER(GCC, >=, 8) && XIEITE_LANG_VER(CPP, >=, 2011))
#		define XIEITE_ATTR_FALLTHROUGH() [[fallthrough]]
#	elif XIEITE_COMPILER_TYPE_CLANG && XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_FALLTHROUGH() [[clang::fallthrough]]
#	elif XIEITE_COMPILER_VER(GCC, >=, 7) || XIEITE_COMPILER_VER(LLC, >=, 125, 5) || (XIEITE_COMPILER_VER(LLC, <, 125) && XIEITE_COMPILER_VER(LLC, >=, 124, 12))
#		define XIEITE_ATTR_FALLTHROUGH() __attribute__((fallthrough))
#	elif XIEITE_XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FALLTHROUGH() __fallthrough
#	else
#		define XIEITE_ATTR_FALLTHROUGH() void()
#	endif
#	define XIEITE_ATTR_FAR DETAIL_XIEITE_ATTR(GCC, gnu, far)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FAST_CALL __fastcall
#	else
#		define XIEITE_ATTR_FAST_CALL DETAIL_XIEITE_ATTR(GCC, gnu, fastcall)
#	endif
#	define XIEITE_ATTR_FAST_INTERRUPT DETAIL_XIEITE_ATTR(GCC, gnu, fast_interrupt)
#	define XIEITE_ATTR_FD(...) DETAIL_XIEITE_ATTR(GCC, gnu, fd_arg, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_FD_READ(...) DETAIL_XIEITE_ATTR(GCC, gnu, fd_arg_read, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_FD_WRITE(...) DETAIL_XIEITE_ATTR(GCC, gnu, fd_arg_write, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_FLAG_ENUM DETAIL_XIEITE_ATTR(CLANG, clang, flag_enum)
#	define XIEITE_ATTR_FLAT DETAIL_XIEITE_ATTR(GCC, gnu, flatten)
#	define XIEITE_ATTR_FORCE_ALIGN_ARG_PTR DETAIL_XIEITE_ATTR(GCC, gnu, force_align_arg_pointer)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_FORCE_INLINE [[msvc::forceinline]]
#	else
#		define XIEITE_ATTR_FORCE_INLINE DETAIL_XIEITE_ATTR(GCC, gnu, always_inline)
#	endif
#	define XIEITE_ATTR_FMT(...) DETAIL_XIEITE_ATTR(GCC, gnu, format, (__VA_ARGS__))
#	define XIEITE_ATTR_FMT_ARG(idx) DETAIL_XIEITE_ATTR(GCC, gnu, format_arg, (idx))
#	define XIEITE_ATTR_FMT_MATCH(...) DETAIL_XIEITE_ATTR(GCC, gnu, format_matches, (__VA_ARGS__))
#	define XIEITE_ATTR_GC DETAIL_XIEITE_ATTR(CLANG, clang, objc_gc)
#	define XIEITE_ATTR_GLOBAL DETAIL_XIEITE_ATTR(,, global)
#	define XIEITE_ATTR_GNU_INLINE DETAIL_XIEITE_ATTR(GCC, gnu, gnu_inline)
#	define XIEITE_ATTR_GRID_CONST DETAIL_XIEITE_ATTR(,, grid_constant)
#	define XIEITE_ATTR_GUARD DETAIL_XIEITE_ATTR(CLANG, clang, guard, (nocf))
#	define XIEITE_ATTR_GUARDED DETAIL_XIEITE_ATTR(CLANG, clang, guarded_var)
#	define XIEITE_ATTR_GUARDED_BY(...) DETAIL_XIEITE_ATTR(,, guarded_by, (__VA_ARGS__))
#	define XIEITE_ATTR_HOST DETAIL_XIEITE_ATTR(,, host)
#	define XIEITE_ATTR_HOT DETAIL_XIEITE_ATTR(GCC, gnu, hot)
#	define XIEITE_ATTR_IB_ACTION DETAIL_XIEITE_ATTR(CLANG, clang, ibaction)
#	define XIEITE_ATTR_IB_OUTLET DETAIL_XIEITE_ATTR(CLANG, clang, iboutlet)
#	define XIEITE_ATTR_IB_OUTLET_COLLECTION DETAIL_XIEITE_ATTR(CLANG, clang, iboutletcollection)
#	define XIEITE_ATTR_IFUNC(resolver) DETAIL_XIEITE_ATTR(GCC, gnu, ifunc, (resolver))
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_IMPORT __declspec(dllimport)
#	else
#		define XIEITE_ATTR_IMPORT DETAIL_XIEITE_ATTR(GCC, gnu, dllimport)
#	endif
#	define XIEITE_ATTR_IMPORT_MODULE(name) DETAIL_XIEITE_ATTR(CLANG, clang, import_module, (name))
#	define XIEITE_ATTR_IMPORT_NAME(name) DETAIL_XIEITE_ATTR(CLANG, clang, import_name, (name))
#	define XIEITE_ATTR_INDEPENDENT_CLASS DETAIL_XIEITE_ATTR(CLANG, clang, objc_independent_class)
#	define XIEITE_ATTR_INHERIT_MULTIPLE DETAIL_XIEITE_ATTR(CLANG,, __multiple_inheritance)
#	define XIEITE_ATTR_INHERIT_SINGLE DETAIL_XIEITE_ATTR(CLANG,, __single_inheritance)
#	define XIEITE_ATTR_INHERIT_UNSPEC DETAIL_XIEITE_ATTR(CLANG,, __unspecified_inheritance)
#	define XIETIE_ATTR_INHERIT_VIRTUAL DETAIL_XIEITE_ATTR(CLANG,, __virtual_inheritance)
#	define XIEITE_ATTR_INIT_PRIORITY(...) DETAIL_XIEITE_ATTR(GCC, gnu, init_priority, (__VA_ARGS__))
#	define XIEITE_ATTR_INIT_SEG XIEITE_PRAGMA_CLANG(init_seg())
#	define XIEITE_ATTR_INTEL_OCL_BICC DETAIL_XIEITE_ATTR(CLANG, clang, intel_ocl_bicc)
#	define XIEITE_ATTR_INTEL_REQD_SUB_GROUP_SIZE DETAIL_XIEITE_ATTR(,, intel_reqd_sub_group_size)
#	define XIEITE_ATTR_INTERNAL DETAIL_XIEITE_ATTR(GCC, gnu, visibility, ("internal"))
#	define XIEITE_ATTR_INTERNAL_LINKAGE DETAIL_XIEITE_ATTR(CLANG, clang, internal_linkage)
#	define XIEITE_ATTR_INTERRUPT(...) DETAIL_XIEITE_ATTR(GCC, gnu, interrupt, __VA_OPT__((type)))
#	define XIEITE_ATTR_INTERRUPT_HANDLER DETAIL_XIEITE_ATTR(GCC, gnu, interrupt_handler)
#	define XIEITE_ATTR_INTERRUPT_SAVE_FP(type) DETAIL_XIEITE_ATTR(,, interrupt_save_fp, (type))
#	define XIEITE_ATTR_ISR DETAIL_XIEITE_ATTR(GCC, gnu, isr)
#	define XIEITE_ATTR_KSPISUSP DETAIL_XIEITE_ATTR(GCC, gnu, kspisusp)
#	define XIEITE_ATTR_LAUNCH_BOUNDS(...) DETAIL_XIEITE_ATTR(,, launch_bounds, (__VA_ARGS__))
#	define XIEITE_ATTR_LAYOUT_VER DETAIL_XIEITE_ATTR(,, layout_version)
#	define XIEITE_ATTR_LEAF DETAIL_XIEITE_ATTR(GCC, gnu, leaf)
#	define XIEITE_ATTR_LIFETIME_BOUND DETAIL_XIEITE_ATTR(CLANG, clang, lifetimebound)
#	define XIEITE_ATTR_LIFETIME_CAPTURE_BY(param) DETAIL_XIEITE_ATTR(CLANG, clang, lifetime_capture_by, (param))
#	if XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_LIKELY [[likely]]
#	else
#		define XIEITE_ATTR_LIKELY
#	endif
#	define XIEITE_ATTR_LOADER_UNINIT DETAIL_XIEITE_ATTR(CLANG, clang, loader_uninitialized)
#	define XIEITE_ATTR_LOCAL DETAIL_XIEITE_ATTR(GCC, gnu, visibility, ("hidden"))
#	define XIEITE_ATTR_LOCKABLE DETAIL_XIEITE_ATTR(,, lockable)
#	if XIEITE_ARCH_TYPE_BLACKFIN || XIEITE_ARCH_TYPE_POWERPC || XIEITE_ARCH_TYPE_RS_6000
#		define XIEITE_ATTR_LONG_CALL DETAIL_XIEITE_ATTR(GCC, gnu, longcall)
#	else
#		define XIEITE_ATTR_LONG_CALL DETAIL_XIEITE_ATTR(GCC, gnu, long_call)
#	endif
#	define XIEITE_ATTR_LTO_PUBLIC DETAIL_XIEITE_ATTR(CLANG, clang, lto_visibility_public)
#	define XIEITE_ATTR_M68K_RTD DETAIL_XIEITE_ATTR(CLANG, clang, m68k_rtd)
#	define XIEITE_ATTR_MALLOC(...) DETAIL_XIEITE_ATTR(GCC, gnu, malloc, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_MANAGED DETAIL_XIEITE_ATTR(,, __managed__)
#	define XIEITE_ATTR_MATRIX DETAIL_XIEITE_ATTR(CLANG, clang, matrix_type)
#	define XIEITE_ATTR_MAY_ALIAS DETAIL_XIEITE_ATTR(GCC, gnu, may_alias)
#	define XIEITE_ATTR_MAYBE_UNDEF DETAIL_XIEITE_ATTR(CLANG, clang, maybe_undef)
#	define XIEITE_ATTR_METHOD_FAMILY(family) DETAIL_XIEITE_ATTR(CLANG, clang, objc_method_family, (family))
#	define XIEITE_ATTR_MICROMIPS DETAIL_XIEITE_ATTR(GCC, gnu, micromips)
#	define XIEITE_ATTR_MIG_SERVER_ROUTINE DETAIL_XIEITE_ATTR(CLANG, clang, mig_server_routine)
#	define XIEITE_ATTR_MIN_SIZE DETAIL_XIEITE_ATTR(CLANG, clang, minsize)
#	define XIEITE_ATTR_MIN_VEC_WIDTH(...) DETAIL_XIEITE_ATTR(CLANG, clang, min_vector_width, (__VA_ARGS__))
#	define XIEITE_ATTR_MIPS16 DETAIL_XIEITE_ATTR(GCC, gnu, mips16)
#	define XIEITE_ATTR_MODE(name) DETAIL_XIEITE_ATTR(GCC, gnu, mode, (name))
#	define XIEITE_ATTR_MODEL(name) DETAIL_XIEITE_ATTR(GCC, gnu, model_name, (name))
#	define XIEITE_ATTR_MS_ABI DETAIL_XIEITE_ATTR(GCC, gnu, ms_abi)
#	define XIEITE_ATTR_MS_HOOK_PROLOGUE DETAIL_XIEITE_ATTR(GCC, gnu, ms_hook_prologue)
#	define XIEITE_ATTR_MS_STRUCT DETAIL_XIEITE_ATTR(GCC, gnu, ms_struct)
#	define XIEITE_ATTR_MUST_TAIL DETAIL_XIEITE_ATTR(GCC, gnu, musttail)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NAKED __declspec(naked)
#	else
#		define XIEITE_ATTR_NAKED DETAIL_XIEITE_ATTR(GCC, gnu, naked)
#	endif
#	define XIEITE_ATTR_NEAR DETAIL_XIEITE_ATTR(GCC, gnu, near)
#	define XIEITE_ATTR_NEON_POLYVEC DETAIL_XIEITE_ATTR(CLANG, clang, neon_polyvector_type)
#	define XIEITE_ATTR_NEON_VEC DETAIL_XIEITE_ATTR(CLANG, clang, neon_vector_type)
#	define XIEITE_ATTR_NEST DETAIL_XIEITE_ATTR(GCC, gnu, nesting)
#	define XIEITE_ATTR_NMI_HANDLER DETAIL_XIEITE_ATTR(GCC, gnu, nmi_handler)
#	define XIEITE_ATTR_NO_ALIAS DETAIL_XIEITE_ATTR(,, noalias)
#	define XIEITE_ATTR_NO_BUILTIN DETAIL_XIEITE_ATTR(CLANG, clang, no_builtin)
#	define XIEITE_ATTR_NO_CALLER_SAVED_REGS DETAIL_XIEITE_ATTR(GCC, gnu, no_caller_saved_registers)
#	define XIEITE_ATTR_NO_CF_CHECK DETAIL_XIEITE_ATTR(GCC, gnu, nocf_check)
#	define XIEITE_ATTR_NO_CF_RETURN_RETAIN DETAIL_XIEITE_ATTR(CLANG, clang, cf_returns_not_retained)
#	define XIEITE_ATTR_NO_CLONE DETAIL_XIEITE_ATTR(GCC, gnu, noclone)
#	define XIEITE_ATTR_NO_CO_LIFETIME_BOUND DETAIL_XIEITE_ATTR(CLANG, clang, coro_disable_lifetimebound)
#	define XIEITE_ATTR_NO_COMMON DETAIL_XIEITE_ATTR(CLANG, clang, nocommon)
#	define XIEITE_ATTR_NO_CONVERGENT DETAIL_XIEITE_ATTR(CLANG, clang, noconvergent)
#	define XIEITE_ATTR_NO_DEBUG DETAIL_XIEITE_ATTR(,, nodebug)
#	define XIEITE_ATTR_NO_DEREF DETAIL_XIEITE_ATTR(CLANG, clang, noderef)
#	define XIEITE_ATTR_NO_DESTROY DETAIL_XIEITE_ATTR(CLANG, clang, no_destroy)
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_NO_DISCARD [[nodiscard]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NO_DISCARD __checkReturn
#	else
#		define XIEITE_ATTR_NO_DISCARD DETAIL_XIEITE_ATTR(GCC, gnu, warn_unused_result)
#	endif
#	define XIEITE_ATTR_NO_DUPLICATE DETAIL_XIEITE_ATTR(CLANG, clang, noduplicate)
#	define XIEITE_ATTR_NO_ESCAPE DETAIL_XIEITE_ATTR(CLANG, clang, noescape)
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_NO_EXCEPT noexcept(true)
#	elif XIEITE_LANG_VER(CPP, >=, 2011)
#		define XIEITE_ATTR_NO_EXCEPT throw()
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NO_EXCEPT __declspec(nothrow)
#	else
#		define XIEITE_ATTR_NO_EXCEPT DETAIL_XIEITE_ATTR(,, nothrow)
#	endif
#	define XIEITE_ATTR_NO_EXPLICIT_INSTANT DETAIL_XIEITE_ATTR(CLANG, clang, exclude_from_explicit_instantiation)
#	define XIEITE_ATTR_NO_ICF DETAIL_XIEITE_ATTR(GCC, gnu, no_icf)
#	define XIEITE_ATTR_NO_INIT_ALL DETAIL_XIEITE_ATTR(,, no_init_all)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_NO_INLINE __declspec(noinline)
#	else
#		define XIEITE_ATTR_NO_INLINE DETAIL_XIEITE_ATTR(GCC, gnu, noinline)
#	endif
#	define XIEITE_ATTR_NO_INSTRUMENT DETAIL_XIEITE_ATTR(GCC, gnu, no_instrument_function)
#	define XIEITE_ATTR_NO_IPA DETAIL_XIEITE_ATTR(GCC, gnu, noipa)
#	define XIEITE_ATTR_NO_MERGE DETAIL_XIEITE_ATTR(CLANG, clang, nomerge)
#	define XIEITE_ATTR_NO_MICROMIPS DETAIL_XIEITE_ATTR(GCC, gnu, nomicromips)
#	define XIEITE_ATTR_NO_MIPS16 DETAIL_XIEITE_ATTR(GCC, gnu, nomips16)
#	define XIEITE_ATTR_NO_NS_RETURN_RETAIN DETAIL_XIEITE_ATTR(CLANG, clang, ns_returns_not_retained)
#	define XIEITE_ATTR_NO_OPTIMIZE DETAIL_XIEITE_ATTR(CLANG, clang, optnone)
#	define XIEITE_ATTR_NO_OS_RETURN_RETAIN DETAIL_XIEITE_ATTR(CLANG, clang, os_returns_not_retained)
#	define XIEITE_ATTR_NO_PLT DETAIL_XIEITE_ATTR(GCC, gnu, noplt)
#	define XIEITE_ATTR_NO_PROFILE_INSTRUMENT DETAIL_XIEITE_ATTR(GCC, gnu, no_profile_instrument_function)
#	define XIEITE_ATTR_NO_RANDOM_LAYOUT DETAIL_XIEITE_ATTR(GCC, gnu, no_randomize_layout)
#	define XIEITE_ATTR_NO_REORDER DETAIL_XIEITE_ATTR(GCC, gnu, no_reorder)
#	if XIEITE_LANG_VER(CPP, >=, 2011) || XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_NO_RETURN [[noreturn]]
#	elif XIEITE_LANG_VER(C, >=, 2011)
#		define XIEITE_ATTR_NO_RETURN _Noreturn
#	else
#		define XIEITE_ATTR_NO_RETURN DETAIL_XIEITE_ATTR(,, noreturn)
#	endif
#	define XIEITE_ATTR_NO_RETURN_ANALYZER DETAIL_XIEITE_ATTR(,, analyzer_noreturn)
#	define XIEITE_ATTR_NO_SANITIZE(...) DETAIL_XIEITE_ATTR(GCC, gnu, no_sanitize, (__VA_ARGS__))
#	if XIEITE_COMPILER_VER(GCC, >=, 4, 8)
#		define XIEITE_ATTR_NO_SANITIZE_ADDR DETAIL_XIEITE_ATTR(GCC, gnu, no_sanitize_address)
#	else
#		define XIEITE_ATTR_NO_SANITIZE_ADDR DETAIL_XIEITE_ATTR(,, no_address_safety_analysis)
#	endif
#	define XIEITE_ATTR_NO_SANITIZE_COVER DETAIL_XIEITE_ATTR(GCC, gnu, no_sanitize_coverage)
#	define XIEITE_ATTR_NO_SANITIZE_INSTRUMENT DETAIL_XIEITE_ATTR(CLANG, clang, disable_sanitizer_instrumentation)
#	define XIEITE_ATTR_NO_SANITIZE_MEMORY DETAIL_XIEITE_ATTR(CLANG, clang, no_sanitize_memory)
#	define XIEITE_ATTR_NO_SANITIZE_THREAD DETAIL_XIEITE_ATTR(GCC, gnu, no_sanitize_thread)
#	define XIEITE_ATTR_NO_SANITIZE_UNDEF DETAIL_XIEITE_ATTR(GCC, gnu, no_sanitize_undefined)
#	define XIEITE_ATTR_NO_SPECIAL DETAIL_XIEITE_ATTR(CLANG, clang, no_specialization)
#	define XIEITE_ATTR_NO_SPECULATIVE_LOAD_HARDENING DETAIL_XIEITE_ATTR(CLANG, clang, no_speculative_load_hardening)
#	define XIEITE_ATTR_NO_STACK_LIMIT DETAIL_XIEITE_ATTR(GCC, gnu, no_stack_limit)
#	define XIEITE_ATTR_NO_STACK_PROT DETAIL_XIEITE_ATTR(GCC, gnu, no_stack_protector)
#	define XIEITE_ATTR_NO_STACK_SPLIT DETAIL_XIEITE_ATTR(GCC, gnu, no_split_stack)
#	define XIEITE_ATTR_NO_SUBCLASS DETAIL_XIEITE_ATTR(CLANG, clang, objc_subclassing_restricted)
#	define XIEITE_ATTR_NO_SVM DETAIL_XIEITE_ATTR(,, nosvm)
#	define XIEITE_ATTR_NO_TAIL_CALL DETAIL_XIEITE_ATTR(CLANG, clang, disable_tail_calls)
#	define XIEITE_ATTR_NO_TAIL_CALLED DETAIL_XIEITE_ATTR(CLANG, clang, not_tail_called)
#	define XIEITE_ATTR_NO_THREAD_SAFETY_ANALYSIS DETAIL_XIEITE_ATTR(CLANG, clang, no_thread_safety_analysis)
#	if XIEITE_COMPILER_VER(MSVC, >=, 16, 9)
#		define XIEITE_ATTR_NO_UNIQUE_ADDR [[msvc::no_unique_address]]
#	elif XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_NO_UNIQUE_ADDR [[no_unique_address]]
#	else
#		define XIEITE_ATTR_NO_UNIQUE_ADDR
#	endif
#	define XIEITE_ATTR_NO_UNROLL XIEITE_PRAGMA_GCC(GCC nounroll)
#	define XIEITE_ATTR_NO_UNROLL_AND_JAM XIEITE_PRAGMA_CLANG(nounroll_and_jam)
#	define XIEITE_ATTR_NO_UWTABLE DETAIL_XIEITE_ATTR(CLANG, clang, nouwtable)
#	define XIEITE_ATTR_NO_VTABLE DETAIL_XIEITE_ATTR(,, novtable)
#	define XIEITE_ATTR_NONALLOCATING DETAIL_XIEITE_ATTR(CLANG, clang, nonallocating)
#	define XIEITE_ATTR_NONBLOCKING DETAIL_XIEITE_ATTR(CLANG, clang, nonblocking)
#	define XIEITE_ATTR_NONLAZY_CLASS DETAIL_XIEITE_ATTR(CLANG, clang, nonlazy_class)
#	define XIEITE_ATTR_NONNULL DETAIL_XIEITE_ATTR(GCC, gnu, nunnull)
#	define XIEITE_ATTR_NONNULL_IF_NONZERO DETAIL_XIEITE_ATTR(GCC, gnu, nonnull_if_nonzero)
#	define XIEITE_ATTR_NONRUNTIME_PROTOCOL DETAIL_XIEITE_ATTR(CLANG, clang, objc_non_runtime_protocol)
#	define XIEITE_ATTR_NONSTR DETAIL_XIEITE_ATTR(CLANG, clang, nonstring)
#	define XIEITE_ATTR_NS_CONSUME DETAIL_XIEITE_ATTR(CLANG, clang, ns_consumed)
#	define XIEITE_ATTR_NS_CONSUME_SELF DETAIL_XIEITE_ATTR(CLANG, clang, ns_consumes_self)
#	define XIEITE_ATTR_NS_ERROR_DOMAIN(domain) DETAIL_XIEITE_ATTR(,, ns_error_domain, (domain))
#	define XIEITE_ATTR_NS_RETURN_AUTORELEASE DETAIL_XIEITE_ATTR(CLANG, clang, ns_returns_autoreleased)
#	define XIEITE_ATTR_NS_RETURN_RETAIN DETAIL_XIEITE_ATTR(CLANG, clang, ns_returns_retained)
#	define XIEITE_ATTR_NSOBJ DETAIL_XIEITE_ATTR(CLANG, clang, NSObject)
#	if XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_NULL_UNSPEC _Null_unspecified
#	else
#		define XIEITE_ATTR_NULL_UNSPEC
#	endif
#	if XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_NULLABLE _Nullable
#	else
#		define XIEITE_ATTR_NULLABLE
#	endif
#	define XIEITE_ATTR_NVPTX_KERNEL DETAIL_XIEITE_ATTR(CLANG, clang, nvptx_kernel)
#	define XIEITE_ATTR_OMP_ASSUME(...) DETAIL_XIEITE_ATTR(CLANG, omp, assume, (#__VA_ARGS__))
#	define XIEITE_ATTR_OPENCL_CONST DETAIL_XIEITE_ATTR(CLANG, clang, opencl_constant)
#	define XIEITE_ATTR_OPENCL_GENERIC DETAIL_XIEITE_ATTR(CLANG, clang, opencl_generic)
#	define XIEITE_ATTR_OPENCL_GLOBAL DETAIL_XIEITE_ATTR(CLANG, clang, opencl_global)
#	define XIEITE_ATTR_OPENCL_GLOBAL_DEVICE DETAIL_XIEITE_ATTR(CLANG, clang, opencl_global_device)
#	define XIEITE_ATTR_OPENCL_GLOBAL_HOST DETAIL_XIEITE_ATTR(CLANG, clang, opencl_global_host)
#	define XIEITE_ATTR_OPENCL_LOCAL DETAIL_XIEITE_ATTR(CLANG, clang, opencl_local)
#	define XIEITE_ATTR_OPENCL_PRIVATE DETAIL_XIEITE_ATTR(CLANG, clang, opencl_private)
#	define XIEITE_ATTR_OPENCL_UNROLL DETAIL_XIEITE_ATTR(,, opencl_unroll_hint)
#	define XIEITE_ATTR_OPTIMIZE(...) DETAIL_XIEITE_ATTR(GCC, gnu, optimize, (__VA_ARGS__))
#	define XIEITE_ATTR_OS_CONSUME DETAIL_XIEITE_ATTR(CLANG, clang, os_consumed)
#	define XIEITE_ATTR_OS_CONSUME_THIS DETAIL_XIEITE_ATTR(CLANG, clang, os_consumes_this)
#	define XIEITE_ATTR_OS_MAIN DETAIL_XIEITE_ATTR(GCC, gnu, OS_main)
#	define XIEITE_ATTR_OS_RETURN_RETAIN DETAIL_XIEITE_ATTR(CLANG, clang, os_returns_retained)
#	define XIEITE_ATTR_OS_RETURN_RETAIN_ON_NONZERO DETAIL_XIEITE_ATTR(CLANG, clang, os_returns_retained_on_non_zero)
#	define XIEITE_ATTR_OS_RETURN_RETAIN_ON_ZERO DETAIL_XIEITE_ATTR(CLANG, clang, os_returns_retained_on_zero)
#	define XIEITE_ATTR_OS_TASK DETAIL_XIEITE_ATTR(GCC, gnu, OS_task)
#	define XIEITE_ATTR_OVERLOADABLE DETAIL_XIEITE_ATTR(CLANG, clang, overloadable)
#	define XIEITE_ATTR_OWNER(...) DETAIL_XIEITE_ATTR(CLANG, gsl, Owner, (__VA_ARGS__))
#	define XIEITE_ATTR_OWNERSHIP_HOLD(...) DETAIL_XIEITE_ATTR(CLANG, clang, ownership_holds, (__VA_ARGS__))
#	define XIEITE_ATTR_OWNERSHIP_RETURN(...) DETAIL_XIEITE_ATTR(CLANG, clang, ownership_returns, (__VA_ARGS__))
#	define XIEITE_ATTR_OWNERSHIP_TAKE(...) DETAIL_XIEITE_ATTR(CLANG, clang, ownership_takes, (__VA_ARGS__))
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_PACK(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#	else
#		define XIEITE_ATTR_PACK(...) DETAIL_XIEITE_ATTR(GCC, gnu, packed) __VA_ARGS__
#	endif
#	define XIEITE_ATTR_PARAM_TYPESTATE DETAIL_XIEITE_ATTR(CLANG, clang, param_typestate)
#	define XIEITE_ATTR_PASCAL DETAIL_XIEITE_ATTR(CLANG, clang, pascal)
#	define XIEITE_ATTR_PASS_DYNAMIC_OBJ_SIZE DETAIL_XIEITE_ATTR(CLANG, clang, pass_dynamic_object_size)
#	define XIEITE_ATTR_PASS_OBJ_SIZE DETAIL_XIEITE_ATTR(CLANG, clang, pass_object_size)
#	define XIEITE_ATTR_PATCH DETAIL_XIEITE_ATTR(GCC, gnu, patchable_function_entry)
#	define XIEITE_ATTR_PATCH_HYBRID DETAIL_XIEITE_ATTR(CLANG, clang, hybrid_patchable)
#	define XIEITE_ATTR_PCS DETAIL_XIEITE_ATTR(GCC, gnu, pcs)
#	define XIEITE_ATTR_POINTER(...) DETAIL_XIEITE_ATTR(CLANG, gsl, Pointer, (__VA_ARGS__))
#	define XIEITE_ATTR_PRECISE_LIFETIME DETAIL_XIEITE_ATTR(CLANG, clang, objc_precise_lifetime)
#	define XIEITE_ATTR_PREFER_NAME(str) DETAIL_XIEITE_ATTR(CLANG, clang, preferred_name, (str))
#	define XIEITE_ATTR_PREFER_TYPE(...) DETAIL_XIEITE_ATTR(CLANG, clang, preferred_type, (__VA_ARGS__))
#	define XIEITE_ATTR_PRESERVE_ACCESS_IDX DETAIL_XIEITE_ATTR(CLANG, clang, preserve_access_index)
#	define XIEITE_ATTR_PRESERVE_ALL DETAIL_XIEITE_ATTR(CLANG, clang, preserve_all)
#	define XIEITE_ATTR_PRESERVE_MOST DETAIL_XIEITE_ATTR(CLANG, clang, preserve_most)
#	define XIEITE_ATTR_PRESERVE_NONE DETAIL_XIEITE_ATTR(CLANG, clang, preserve_none)
#	define XIEITE_ATTR_PRESERVE_STATIC_OFFSET DETAIL_XIEITE_ATTR(CLANG, clang, preserve_static_offset)
#	define XIEITE_ATTR_PROT DETAIL_XIEITE_ATTR(GCC, gnu, visibility, ("protected"))
#	define XIEITE_ATTR_PROTOCOL_REQUIRE_EXPLICIT_IMPL DETAIL_XIEITE_ATTR(CLANG, clang, objc_protocol_requires_explicit_implementation)
#	define XIEITE_ATTR_PT_GUARDED DETAIL_XIEITE_ATTR(,, pt_guarded_var)
#	define XIEITE_ATTR_PT_GUARDED_BY(...) DETAIL_XIEITE_ATTR(,, pt_guarded_by, (__VA_ARGS__))
#	define XIEITE_ATTR_PTR_WITH_TYPE_TAG(...) DETAIL_XIEITE_ATTR(CLANG, clang, pointer_with_type_tag, (__VA_ARGS__))
#	define XIEITE_ATTR_PTRAUTH_VTABLE_PTR DETAIL_XIEITE_ATTR(CLANG, clang, ptrauth_vtable_pointer)
#	define XIEITE_ATTR_PURE DETAIL_XIEITE_ATTR(GCC, gnu, pure)
#	define XIEITE_ATTR_REG_CALL DETAIL_XIEITE_ATTR(CLANG, gnu, regcall)
#	define XIEITE_ATTR_RELEASE_HANDLE(handle) DETAIL_XIEITE_ATTR(CLANG, clang, release_handle, (handle))
#	define XIEITE_ATTR_RANDOM_LAYOUT DETAIL_XIEITE_ATTR(GCC, gnu, randomize_layout)
#	define XIEITE_ATTR_REENTRANT_CAPABILITY(...) DETAIL_XIEITE_ATTR(CLANG, clang, reentrant_capability, (__VA_ARGS__))
#	define XIEITE_ATTR_REG_PARAM(n) DETAIL_XIEITE_ATTR(GCC, gnu, regparm, (n))
#	define XIEITE_ATTR_REINIT DETAIL_XIEITE_ATTR(CLANG, clang, reinitializes)
#	define XIEITE_ATTR_RELEASE_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, release_capability)
#	define XIEITE_ATTR_RELEASE_GENERIC_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, release_generic_capability)
#	define XIEITE_ATTR_RELEASE_SHARED_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, release_shared_capability)
#	if XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_REPRO [[reproducible]]
#	else
#		define XIEITE_ATTR_REPRO DETAIL_XIEITE_ATTR(GCC, gnu, reproducible)
#	endif
#	define XIEITE_ATTR_REQD_WORK_GROUP_SIZE DETAIL_XIEITE_ATTR(,, reqd_work_group_size)
#	define XIEITE_ATTR_REQUIRE_CAPABILITY(...) DETAIL_XIEITE_ATTR(CLANG, clang, requires_capability, (__VA_ARGS__))
#	define XIEITE_ATTR_REQUIRE_EXCLUSIVE_LOCK DETAIL_XIEITE_ATTR(CLANG, clang, exclusive_locks_required)
#	define XIEITE_ATTR_REQUIRE_PROPERTY_DEF DETAIL_XIEITE_ATTR(CLANG, clang, objc_requires_property_definitions)
#	define XIEITE_ATTR_REQUIRE_SHARED_CAPABILITY(...) DETAIL_XIEITE_ATTR(CLANG, clang, requires_shared_capability, (__VA_ARGS__))
#	define XIEITE_ATTR_REQUIRE_SHARED_LOCK DETAIL_XIEITE_ATTR(CLANG, clang, shared_locks_required)
#	define XIEITE_ATTR_REQUIRE_SUPER DETAIL_XIEITE_ATTR(CLANG, clang, objc_requires_super)
#	define XIEITE_ATTR_RESBANK DETAIL_XIEITE_ATTR(GCC, gnu, resbank)
#	define XIEITE_ATTR_RETAIN DETAIL_XIEITE_ATTR(GCC, gnu, retain)
#	define XIEITE_ATTR_RETURN(kind) DETAIL_XIEITE_ATTR(GCC, gnu, function_return, (kind))
#	define XIEITE_ATTR_RETURN_INNER_PTR DETAIL_XIEITE_ATTR(CLANG, clang, objc_returns_inner_pointer)
#	define XIEITE_ATTR_RETURN_LOCK DETAIL_XIEITE_ATTR(,, lock_returned)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_RETURN_NONNULL _Ret_notnull_
#	else
#		define XIEITE_ATTR_RETURN_NONNULL DETAIL_XIEITE_ATTR(GCC, gnu, returns_nonnull)
#	endif
#	define XIEITE_ATTR_RETURN_TWICE DETAIL_XIEITE_ATTR(GCC, gnu, returns_twice)
#	define XIEITE_ATTR_RETURN_TYPESTATE DETAIL_XIEITE_ATTR(CLANG, clang, return_typestate)
#	define XIEITE_ATTR_RISCV_RVV_VEC_BITS(...) DETAIL_XIEITE_ATTR(,, riscv_rvv_vec_bits, (__VA_ARGS__))
#	define XIEITE_ATTR_RISCV_VEC_CC DETAIL_XIEITE_ATTR(CLANG, riscv, vector_cc)
#	define XIEITE_ATTR_RISCV_VLS_CC DETAIL_XIEITE_ATTR(CLANG, riscv, vls_cc)
#	define XIEITE_ATTR_ROOT_CLASS DETAIL_XIEITE_ATTR(CLANG, clang, objc_root_class)
#	define XIEITE_ATTR_RUNTIME_NAME DETAIL_XIEITE_ATTR(CLANG, clang, objc_runtime_name)
#	define XIEITE_ATTR_RUNTIME_VISIBLE DETAIL_XIEITE_ATTR(CLANG, clang, objc_runtime_visible)
#	define XIEITE_ATTR_SAVE_ALL DETAIL_XIEITE_ATTR(GCC, gnu, saveall)
#	define XIEITE_ATTR_SAVE_VOLATILE DETAIL_XIEITE_ATTR(GCC, gnu, save_volatiles)
#	define XIEITE_ATTR_SCOPED_LOCKABLE DETAIL_XIEITE_ATTR(CLANG, clang, scoped_lockable)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_SECTION(name) __declspec(allocate(name))
#	else
#		define XIEITE_ATTR_SECTION(name) DETAIL_XIEITE_ATTR(GCC, gnu, section, (name))
#	endif
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_SELECT_ANY __declspec(selectany)
#	else
#		define XIEITE_ATTR_SELECT_ANY DETAIL_XIEITE_ATTR(GCC, gnu, selectany)
#	endif
#	define XIEITE_ATTR_SENTINEL(...) DETAIL_XIEITE_ATTR(GCC, gnu, sentinel, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_SET_TYPESTATE(state) DETAIL_XIEITE_ATTR(CLANG, clang, set_typestate, (state))
#	define XIEITE_ATTR_SHARED DETAIL_XIEITE_ATTR(,, shared)
#	define XIEITE_ATTR_SHARED_CAPABILITY(...) DETAIL_XIEITE_ATTR(CLANG, clang, shared_capability)
#	define XIEITE_ATTR_SHARED_LOCK DETAIL_XIEITE_ATTR(,, shared_lock_function)
#	if XIEITE_ARCH_TYPE_BLACKFIN || XIEITE_ARCH_TYPE_POWERPC || XIEITE_ARCH_TYPE_RS_6000
#		define XIEITE_ATTR_SHORT_CALL DETAIL_XIEITE_ATTR(GCC, gnu, shortcall)
#	else
#		define XIEITE_ATTR_SHORT_CALL DETAIL_XIEITE_ATTR(GCC, gnu, short_call)
#	endif
#	define XIEITE_ATTR_SIGNAL DETAIL_XIEITE_ATTR(GCC, gnu, signal)
#	define XIEITE_ATTR_SIMD(...) DETAIL_XIEITE_ATTR(GCC, gnu, simd, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_SIZED_BY(...) DETAIL_XIEITE_ATTR(CLANG, clang, sized_by, (__VA_ARGS__))
#	define XIEITE_ATTR_SIZED_BY_OR_NULL(...) DETAIL_XIEITE_ATTR(CLANG, clang, sized_by_or_nul, (__VA_ARGS__))
#	define XIEITE_ATTR_SP_SWITCH DETAIL_XIEITE_ATTR(GCC, gnu, sp_switch)
#	define XIEITE_ATTR_SPECULATIVE_LOAD_HARDENING DETAIL_XIEITE_ATTR(CLANG, clang, speculative_load_hardening)
#	define XIEITE_ATTR_SSE_REG_PARAM(n) DETAIL_XIEITE_ATTR(GCC, gnu, sseregparm, (n))
#	define XIEITE_ATTR_STACK_PROT DETAIL_XIEITE_ATTR(GCC, gnu, stack_protect)
#	define XIEITE_ATTR_STANDALONE_DEBUG DETAIL_XIEITE_ATTR(CLANG, clang, standalone_debug)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_STD_CALL __cdecl
#	elif XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_STD_CALL __stdcall
#	else
#		define XIEITE_ATTR_STD_CALL DETAIL_XIEITE_ATTR(GCC, gnu, stdcall)
#	endif
#	define XIEITE_ATTR_STRICT_GS_CHECK DETAIL_XIEITE_ATTR(,, strict_gs_check)
#	define XIEITE_ATTR_SUPPRESS DETAIL_XIEITE_ATTR(CLANG, clang, suppress)
#	define XIEITE_ATTR_SWIFT_ASYNC(...) DETAIL_XIEITE_ATTR(CLANG, clang, swift_async, (__VA_ARGS__))
#	define XIEITE_ATTR_SWIFT_ASYNC_CALL DETAIL_XIEITE_ATTR(CLANG, clang, swiftasynccall)
#	define XIEITE_ATTR_SWIFT_ASYNC_CONTEXT DETAIL_XIEITE_ATTR(CLANG, clang, swift_async_context)
#	define XIEITE_ATTR_SWIFT_ASYNC_ERROR(...) DETAIL_XIEITE_ATTR(CLANG, clang, swift_async_error, (__VA_ARGS__))
#	define XIEITE_ATTR_SWIFT_ASYNC_NAME(name) DETAIL_XIEITE_ATTR(,, swift_async_name, (name))
#	define XIEITE_ATTR_SWIFT_ATTR(attr) DETAIL_XIEITE_ATTR(,, swift_attr, (attr))
#	define XIEITE_ATTR_SWIFT_BRIDGE(...) DETAIL_XIEITE_ATTR(,, swift_bridge, (__VA_ARGS__))
#	define XIEITE_ATTR_SWIFT_BRIDGED DETAIL_XIEITE_ATTR(,, swift_bridged_typedef)
#	define XIEITE_ATTR_SWIFT_CALL DETAIL_XIEITE_ATTR(CLANG, clang, swiftcall)
#	define XIEITE_ATTR_SWIFT_CONTEXT DETAIL_XIEITE_ATTR(CLANG, clang, swift_context)
#	define XIEITE_ATTR_SWIFT_ERROR(error) DETAIL_XIEITE_ATTR(,, swift_error, (error))
#	define XIEITE_ATTR_SWIFT_ERROR_RESULT DETAIL_XIEITE_ATTR(CLANG, clang, swift_error_result)
#	define XIEITE_ATTR_SWIFT_INDIRECT_RESULT DETAIL_XIEITE_ATTR(CLANG, clang, swift_indirect_result)
#	define XIEITE_ATTR_SWIFT_NAME(name) DETAIL_XIEITE_ATTR(,, swift_name, (name))
#	define XIEITE_ATTR_SWIFT_NEW_TYPE(kind) DETAIL_XIEITE_ATTR(,, swift_newtype, (kind))
#	define XIEITE_ATTR_SWIFT_OBJECTIVE_C_MEMBERS DETAIL_XIEITE_ATTR(,, swift_objc_members)
#	define XIEITE_ATTR_SWIFT_PRIVATE DETAIL_XIEITE_ATTR(,, swift_private)
#	define XIEITE_ATTR_SYCL_KERNEL DETAIL_XIEITE_ATTR(CLANG, clang, sycl_kernel)
#	define XIEITE_ATTR_SYCL_KERNEL_ENTRY DETAIL_XIEITE_ATTR(CLANG, clang, sycl_kernel_entry)
#	define XIEITE_ATTR_SYCL_SPECIAL_CLASS DETAIL_XIEITE_ATTR(CLANG, clang, sycl_special_class)
#	define XIEITE_ATTR_SYMVER(ver) DETAIL_XIEITE_ATTR(GCC, gnu, symver, (ver))
#	define XIEITE_ATTR_SYS_CALL_LINK DETAIL_XIEITE_ATTR(GCC, gnu, syscall_linkage)
#	define XIEITE_ATTR_SYSV_ABI DETAIL_XIEITE_ATTR(GCC, gnu, sysv_abi)
#	define XIEITE_ATTR_TAINT DETAIL_XIEITE_ATTR(GCC, gnu, tainted_args)
#	define XIEITE_ATTR_TARGET(...) DETAIL_XIEITE_ATTR(GCC, gnu, target, (__VA_ARGS__))
#	define XIEITE_ATTR_TARGET_CLONES(...) DETAIL_XIEITE_ATTR(GCC, gnu, target_clones, (__VA_ARGS__))
#	define XIEITE_ATTR_TARGET_VER(...) DETAIL_XIEITE_ATTR(GCC, gnu, target_version, (__VA_ARGS__))
#	define XIEITE_ATTR_TERMINATED_STR(...) DETAIL_XIEITE_ATTR(GCC, gnu, null_terminated_string_arg, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_TEST_TYPESTATE(state) DETAIL_XIEITE_ATTR(CLANG, clang, test_typestate, (state))
#	define XIEITE_ATTR_TINY_DATA DETAIL_XIEITE_ATTR(GCC, gnu, tiny_data)
#	if XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_THIS_CALL __thiscall
#	else
#		define XIEITE_ATTR_THIS_CALL DETAIL_XIEITE_ATTR(GCC, gnu, thiscall)
#	endif
#	if XIEITE_COMPILER_TYPE_MSVC || XIEITE_COMPILER_TYPE_DATALIGHT_C
#		define XIEITE_ATTR_THREAD __declspec(thread)
#	else
#		define XIEITE_ATTR_THREAD
#	endif
#	define XIEITE_ATTR_THREAD_INTERRUPT DETAIL_XIEITE_ATTR(GCC, gnu, interrupt_thread)
#	define XIEITE_ATTR_TSL_MODEL(kind) DETAIL_XIEITE_ATTR(GCC, gnu, tls_model, (kind))
#	define XIEITE_ATTR_TRANSPARENT_UNION DETAIL_XIEITE_ATTR(GCC, gnu, transparent_union)
#	define XIEITE_ATTR_TRAP DETAIL_XIEITE_ATTR(GCC, gnu, trap_exit)
#	define XIEITE_ATTR_TRIVIAL_ABI DETAIL_XIEITE_ATTR(CLANG, clang, trivial_abi)
#	define XIEITE_ATTR_TRY_ACQUIRE_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, try_acquire_capability)
#	define XIEITE_ATTR_TRY_ACQUIRE_SHARED_CAPABILITY DETAIL_XIEITE_ATTR(CLANG, clang, try_acquire_shared_capability)
#	define XIEITE_ATTR_TRY_EXCLUSIVE_LOCK DETAIL_XIEITE_ATTR(,, exclusive_trylock_function)
#	define XIEITE_ATTR_TRY_SHARED_LOCK DETAIL_XIEITE_ATTR(,, shared_trylock_function)
#	define XIEITE_ATTR_TYPE_TAG_FOR_DATATYPE(...) DETAIL_XIEITE_ATTR(CLANG, clang, type_tag_for_datatype, (__VA_ARGS__))
#	define XIEITE_ATTR_TYPE_VISIBILITY(...) DETAIL_XIEITE_ATTR(CLANG, clang, type_visibility, (__VA_ARGS__))
#	if XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_ATTR_UNAVAIL DETAIL_XIEITE_ATTR(CLANG, clang, unavailable)
#	else
#		define XIEITE_ATTR_UNAVAIL DETAIL_XIEITE_ATTR(GCC, gnu, unavailable)
#	endif
#	define XIEITE_ATTR_UNINIT DETAIL_XIEITE_ATTR(CLANG, clang, uninitialized)
#	if XIEITE_LANG_VER(CPP, >=, 2020)
#		define XIEITE_ATTR_UNLIKELY [[unlikely]]
#	else
#		define XIEITE_ATTR_UNLIKELY
#	endif
#	define XIEITE_ATTR_UNLOCK DETAIL_XIEITE_ATTR(CLANG, clang, unlock_function)
#	define XIEITE_ATTR_UNROLL(...) XIEITE_PRAGMA_GCC(GCC unroll __VA_ARGS__)
#	define XIEITE_ATTR_UNROLL_AND_JAM(...) XIEITE_PRAGMA_CLANG(unroll_and_jam __VA_ARGS__)
#	define XIEITE_ATTR_UNSAFE_BUFFER DETAIL_XIEITE_ATTR(CLANG, clang, unsafe_buffer_usage)
#	if XIEITE_LANG_VER(C, >=, 2023)
#		define XIEITE_ATTR_UNSEQ [[unsequenced]]
#	else
#		define XIEITE_ATTR_UNSEQ DETAIL_XIEITE_ATTR(GCC, gnu, unsequenced)
#	endif
#	if XIEITE_LANG_VER(CPP, >=, 2017)
#		define XIEITE_ATTR_UNUSED [[maybe_unused]]
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_ATTR_UNUSED __pragma(warning(suppress: 4100 4101 4505))
#	else
#		define XIEITE_ATTR_UNUSED DETAIL_XIEITE_ATTR(GCC, gnu, unused)
#	endif
#	define XIEITE_ATTR_USE_HANDLE(handle) DETAIL_XIEITE_ATTR(CLANG, clang, use_handle, (handle))
#	define XIEITE_ATTR_USED DETAIL_XIEITE_ATTR(GCC, gnu, used)
#	define XIEITE_ATTR_USING_IF_EXISTS DETAIL_XIEITE_ATTR(CLANG, clang, using_if_exists)
#	define XIEITE_ATTR_UUID DETAIL_XIEITE_ATTR(,, uuid)
#	define XIEITE_ATTR_VEC DETAIL_XIEITE_ATTR(GCC, gnu, function_vector)
#	define XIEITE_ATTR_VEC_CALL DETAIL_XIEITE_ATTR(CLANG, clang, vector_call)
#	define XIEITE_ATTR_VEC_HINT DETAIL_XIEITE_ATTR(,, vec_type_hint)
#	define XIEITE_ATTR_VEC_RET DETAIL_XIEITE_ATTR(CLANG, clang, vecreturn)
#	define XIEITE_ATTR_VER(id) DETAIL_XIEITE_ATTR(GCC, gnu, version_id, (id))
#	define XIEITE_ATTR_VISIBLE DETAIL_XIEITE_ATTR(GCC, gnu, externally_visible)
#	define XIEITE_ATTR_VLIW DETAIL_XIEITE_ATTR(GCC, gnu, vliw)
#	define XIEITE_ATTR_WARN(msg) DETAIL_XIEITE_ATTR(GCC, gnu, warning, (msg))
#	define XIEITE_ATTR_WEAK DETAIL_XIEITE_ATTR(GCC, gnu, weak)
#	define XIEITE_ATTR_WEAK_IMPORT DETAIL_XIEITE_ATTR(CLANG, clang, weak_import)
#	define XIEITE_ATTR_WEAK_REF(...) DETAIL_XIEITE_ATTR(GCC, gnu, weakref, __VA_OPT__((__VA_ARGS__)))
#	define XIEITE_ATTR_WORK_GROUP_SIZE_HINT(...) DETAIL_XIEITE_ATTR(,, work_group_size_hint)
#	define XIEITE_ATTR_XRAY_ALWAYS_INSTRUMENT DETAIL_XIEITE_ATTR(CLANG, clang, xray_always_instrument)
#	define XIEITE_ATTR_XRAY_LOG_ARGS(...) DETAIL_XIEITE_ATTR(CLANG, clang, xray_always_instrument, (__VA_ARGS__))
#	define XIEITE_ATTR_XRAY_NEVER_INSTRUMENT DETAIL_XIEITE_ATTR(CLANG, clang, xray_log_args)
#	define XIEITE_ATTR_ZERO_REGS(choice) DETAIL_XIEITE_ATTR(GCC, gnu, zero_call_used_regs, (choice))
#
#	define DETAIL_XIEITE_ATTR(compiler, ns, attr, ...) XIEITE_IF(XIEITE_AND(XIEITE_ANY(compiler))(XIEITE_NONE(ns)))(XIEITE_IF(XIEITE_COMPILER_TYPE_##compiler)(attr)())(XIEITE_IF(XIEITE_HAS_ATTR(attr))(XIEITE_IF(XIEITE_AND(XIEITE_ANY(ns))(XIEITE_OR(XIEITE_LANG_VER(CPP, >=, 2011))(XIEITE_LANG_VER(C, >=, 2023))))([[ns::attr __VA_ARGS__]])(__attribute__((attr __VA_ARGS__))))(XIEITE_IF(XIEITE_HAS_DECLSPEC(attr))(__declspec(attr))()))
#endif

// https://gcc.gnu.org/onlinedocs/gcc/Function-Attributes.html
// https://clang.llvm.org/docs/AttributeReference.html
// https://github.com/isar/libmdbx/blob/master/src/preface.h

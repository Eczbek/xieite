#ifndef DETAIL_XTE_HEADER_SYS_CPU_RELAX
#	define DETAIL_XTE_HEADER_SYS_CPU_RELAX
#
#	include "../preproc/arch.hpp"
#	include "../preproc/attr.hpp"
#	include "../preproc/compiler.hpp"
#	include <thread>
#
#	if XTE_COMPILER_TYPE_MSVC
#		include <intrin.h>
#	endif

namespace xte {
	XTE_ATTR_FORCE_INLINE void cpu_relax() noexcept {
#	if XTE_ARCH_TYPE_X86_64
#		if XTE_COMPILER_TYPE_MSVC
		_mm_pause();
#		else
		__builtin_ia32_pause();
#		endif
#	elif XTE_ARCH_TYPE_AARCH64
#		if XTE_COMPILER_TYPE_MSVC
		__yield();
#		else
		asm volatile("yield" ::: "memory");
#		endif
#	elif XTE_ARCH_TYPE_RISC_V
		asm volatile("pause" ::: "memory");
#	elif XTE_ARCH_TYPE_POWERPC
		asm volatile("or 27,27,27" ::: "memory");
#	elif XTE_ARCH_TYPE_IBM_SYSTEM_390 \
		|| XTE_ARCH_TYPE_LOONGARCH \
		|| XTE_ARCH_TYPE_MIPS \
		|| XTE_ARCH_TYPE_SPARC
		asm volatile("nop" ::: "memory");
#	else
		std::this_thread::yield();
#	endif
	}
}

#endif

// Thanks to Ian Pike (https://github.com/Rinzii) for original code

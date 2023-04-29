#pragma once

#if defined(__amd64) || defined(__amd64__) || defined(__x86_64) || defined(__x86_64__)
#	define XIEITE_ARCHITECTURE_TYPE_X86_64
#elif defined(i386) || defined(__i386) || defined(__i386__)
#	define XIEITE_ARCHITECTURE_TYPE_X86_32
#elif defined(__aarch64__)
#	define XIEITE_ARCHITECTURE_TYPE_ARM_64
#endif

#ifndef DETAIL_XTE_HEADER_SYS_SEGFAULT
#	define DETAIL_XTE_HEADER_SYS_SEGFAULT
#
#include <csignal>

namespace xte {
	inline void segfault() noexcept {
		std::raise(SIGSEGV);
	}
}

#endif

#ifndef DETAIL_XTE_HEADER_SYS_SEGFAULT
#	define DETAIL_XTE_HEADER_SYS_SEGFAULT

namespace xte {
	inline void segfault() noexcept {
		*static_cast<volatile int*>(nullptr);
	}
}

#endif
